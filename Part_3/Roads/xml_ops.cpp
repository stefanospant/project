#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <utility>
#include <vector>

#include "road.h"

using namespace std;

void check_highway(string & type){
  if(!type.compare("motorway") || !type.compare("primary")){
    return ;
  }
  else if(!type.compare("residential") || !type.compare("secondary")){
    return ;
  }
  else if(!type.compare("service") || !type.compare("tertiary")){
    return ;
  }
  else if(!type.compare("trunk") || !type.compare("unclassified")){
    return ;
  }
  type.clear();
}

int compare(const string & s1, const string & s2){
  size_t l1{s1.length()}, l2{s2.length()};
  if(l1 > l2)
    return 1;
  else if (l2 > l1)
    return -1;
  else
    return s1.compare(s2);
}

size_t binary_search(vector<node> & nodes, string id){
  size_t l{0}, r{nodes.size()-1}, i{(l+r)/2};
  node r_node;
  int comp = compare(nodes[i].id, id);
  while(comp){
    //cout << "Searching " << id << " comparing with " << nodes[i].id << " i " << i;
    //cout << " l,r " << l << " " << r << ' ' << comp << endl;
    if(comp > 0)
      r = --i;
    else
      l = ++i;
    i = (l+r)/2;
    comp = compare(nodes[i].id, id);
  }
  //cout << "size " << nodes.size() << " i " << i  << " id " << id << '\n';
  //nodes[i].print();
  return i;
}

//write nodes writes the athens.csv file with the roads info
//and returns a vector of the indexes of a way's nodes in the
//general nodes vector
inline vector<int> write_nodes(ofstream & out, vector<node> & nodes, vector<string> & nds){
  size_t target{0};
  vector<int> node_i;
  for(size_t i=0; i<nds.size(); i++){
    target = binary_search(nodes, nds[i]);
    out << ", " << nodes[target].lat << ", " << nodes[target].lon;
    node_i.push_back(target);
  }
  return node_i;
}

bool parse_xml(vector<road> & roads, vector<node> & nodes, const string &data_s,
  const string &out_s){
  ifstream data(data_s);
  ofstream out(out_s);
  vector<string> nds;
  node t_node;
  road t_road;
  string temp{}, type{}, id{};
  int counter{0};
  size_t max = std::numeric_limits<streamsize>::max();
  nodes.reserve(3000000);
  //ignore the first 3 lines of the xml file
  data.ignore(max, '\n');
  data.ignore(max, '\n');
  data.ignore(max, '\n');
  //start reading nodes;
  while(true){
    data >> temp;
    //cout << "Read " << temp << endl;
    //if it's not a node tag break
    if(!temp.compare("<node")){
      data >> temp;
      //copy the id
      t_node.id.assign(temp, 4, temp.length()-5);
      //t_node.id = std::move(temp.substr(4, temp.length()-5));
      //parse latitude
      data >> temp;
      t_node.lat = stod(temp.substr(5));
      //parse longitute
      data >> temp;
      t_node.lon = stod(temp.substr(5));
      //move node to the vector
      nodes.push_back(move(t_node));
      //cout << "Node read" << endl;
      counter++;
    }
    else if(!temp.compare("<way")){
      break;
    }
    //ignore the rest of the line
    data.ignore(max, '\n');
  }

  while(true){
    if(!temp.compare("<way")){
      data >> temp;
      id.assign(temp, 4, temp.length()-5);
      //id = temp.substr(4, temp.length()-5);
    }
    else if(!temp.compare("<nd")){
      data >> temp;
      nds.push_back(move(temp.substr(5, temp.length()-8)));
    }
    else if(!temp.compare("<tag")){
      data >> temp;
      if(!temp.compare("k=\"highway\"")){
        data >> temp;
        type = temp.substr(3, temp.length()-6);
        //cout << "Type is " << type <<'\n';
        //check if it's a highway we're interested in
        check_highway(type);
      }
    }
    else if(!temp.compare("</way>")){
      //write road to file if valid
      if(!type.empty()){
        out << id << ", " << type;
        t_road.nodes = write_nodes(out, nodes, nds);
        out << endl;
        t_road.id = move(id);
        t_road.type = move(type);
        roads.push_back(move(t_road));
      }
      id.clear();
      type.clear();
      nds.clear();
    }
    else if(!temp.compare("<relation")){
      //relation tags are in the end of the file so we're done
      break;
    }
    data.ignore(max, '\n');
    data >> temp;
  }
  return true;
}
