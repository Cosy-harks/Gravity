#include "gravity.h"

gravity::pulls(const std::vector<double>& pos1, const std::vector<double>& pos2, std::vector<double>& vec1, std::vector<double>& vec2, const double& M1, const double& M2, const double& distance){
	// delta distances by axis
	double dx = pos1[0] - pos2[0];
    double dy = pos1[1] - pos2[1];
    double dz = pos1[2] - pos2[2];
	
	// force from the two masses
	double f = gravForce(M1, M2, distance);
	
	// the gravity acceleration vector
	std::vector<double> accvec = std::vector<double>(dx*f*deltaTime, dy*f*deltaTime, dz*f*deltaTime);
	//kg mm / s
	double dmass = d*M2;
	vec2[0] += accvec[0] / dmass; //m/s
	vec2[1] += accvec[1] / dmass;
	vec2[2] += accvec[2] / dmass;
	
    dmass = d*one.mass;
	vec1[0] -= accvec[0] / dmass;
	vec1[1] -= accvec[1] / dmass;
	vec1[2] -= accvec[2] / dmass;
}

double gravForce(const double& M1, const double& M2, const double& d){
	return (G * M1 * M2 / sq(d));
}
