#include <vector>
#include <string>
#include <cmath>
#include <limits>

#include "minmax.h"

using namespace std;

double euclid_dist(const vector<double> & p1, const vector<double> & p2){
	double temp{},ed{0.0};
	for(size_t i=0; i<p1.size(); i++){
		temp=abs(p1[i]-p2[i]);
		ed+=temp*temp;
	}
	ed = sqrt(ed);
	return ed;
}

void computeDFD(const vector<vector<double>> & pointsA,
	const vector<vector<double>> & pointsB,double & distance){
	int m=pointsA.size(), n=pointsB.size();
	double L[m+1][n+1];
	double maxdbl{std::numeric_limits<double>::max()};
	L[0][0]=0.0;
	for(int i=1; i<m+1; i++)
		L[i][0] = maxdbl;
	for(int i=1; i<n+1; i++)
		L[0][i] = maxdbl;
	for(int i=1; i<m+1; i++)
		for(int j=1; j<n+1; j++)
			L[i][j] = MYmax(euclid_dist(pointsA[i-1],pointsB[j-1]),
				MYmin(L[i-1][j-1],MYmin(L[i-1][j],L[i][j-1])));
	distance = L[m][n];
	return ;
}

void computeDTW(const vector<vector<double>> & pointsA,
	const vector<vector<double>> & pointsB,double & distance){
	int m=pointsA.size(), n=pointsB.size();
	double L[m+1][n+1];
	double maxdbl{std::numeric_limits<double>::max()};
	L[0][0]=0.0;
	for(int i=1; i<m+1; i++)
		L[i][0] = maxdbl;
	for(int i=1; i<n+1; i++)
		L[0][i] = maxdbl;

	for(int i=1; i<m+1; i++)
		for(int j=1; j<n+1; j++)
			L[i][j] = euclid_dist(pointsA[i-1],pointsB[j-1]) +
				min(L[i-1][j-1],min(L[i-1][j],L[i][j-1]));
	distance = L[m][n];
	return ;
}

void find_distance(const vector<vector<double>> & pointsA,
	const vector<vector<double>> & pointsB, string dist, double & distance){
	if(dist=="DFT")
			computeDFD(pointsA,pointsB,distance);
	else if(dist=="DTW")
			computeDTW(pointsA,pointsB,distance);
//	else if(dist=="..something else..")

	return ;
}
