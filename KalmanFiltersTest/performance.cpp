#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Eigen/Dense"
#include "measurement_package.h"
#include "tracking.h"

using namespace std;

VectorXd CalculateRMSE(const vector<VectorXd> &estimations,
	const vector<VectorXd> &ground_truth) {

	VectorXd rmse(4);
	rmse << 0, 0, 0, 0;
	VectorXd sum(4);
	rmse << 0, 0, 0, 0;

	// TODO: YOUR CODE HERE

	// check the validity of the following inputs:
	//  * the estimation vector size should not be zero
	//  * the estimation vector size should equal ground truth vector size
	// ... your code here

	if (estimations.size() == 0 ||
		estimations.size() != ground_truth.size()) {
		cout << "Incorrect estimation or ground_truth data" << endl;
		return rmse;
	}

	//accumulate squared residuals
	for (int i = 0; i < estimations.size(); ++i) {
		// ... your code here
		VectorXd estimation = estimations[i];
		VectorXd ground_truth_item = ground_truth[i];

		VectorXd residual = estimation - ground_truth_item;

		VectorXd square = residual.array() * residual.array();
		sum += square;
	}

	//calculate the mean
	// ... your code here
	VectorXd mean = sum / estimations.size();

	//calculate the squared root
	// ... your code here
	rmse = mean.array().sqrt();

	//return the result
	return rmse;
}