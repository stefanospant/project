#include <vector>
#include "curve.h"
#include "distance_ops.h"

using namespace std;

bool lloyds_assignment(vector<real_curve *> centroids,
  vector<real_curve *> curves, vector<vector<real_curve *>> & assignment){

  int jmin{};
  double distmin{}, dist{};

  if(!assignment.empty())
    assignment.resize(centroids.size());

  for(int i=0; i<curves.size(); i++){
    jmin = 0;
    const vector<vector<double>> & c_points = curves[i]->get_points();
    computeDFD(c_points, centroids[0]->get_points(), distmin);
    for (int j=1; j<centroids.size(); j++){
      computeDFD(c_points, centroids[j]->get_points(), dist);
      if(dist < distmin){
        distmin = dist;
        jmin = j;
      }
    }
    //assign curve i to centroid jmin
    assignment[jmin].push_back(curves[i]);
  }

  return true;
}
