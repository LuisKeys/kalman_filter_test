#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <vector>
#include "Eigen/Dense"
#include "measurement_package.h"
#include "tracking.h"

using namespace std;

MatrixXd CalculateJacobian(const VectorXd& x_state) {

	MatrixXd Hj(3, 4);
	//recover state parameters
	float px = x_state(0);
	float py = x_state(1);
	float vx = x_state(2);
	float vy = x_state(3);

	//TODO: YOUR CODE HERE 
	float px_2 = px * px;
	float py_2 = py * py;
	float diag_2 = px_2 + py_2;
	float g = sqrt(diag_2);
	float g_3_2 = g * g * g;

	//check division by zero
	if (diag_2 < 0.0001)
		cout << "Error, division by 0";

	//compute the Jacobian matrix
	//Row 1	
	Hj(0, 0) = px / g;
	Hj(0, 1) = py / g;
	Hj(0, 2) = 0;
	Hj(0, 3) = 0;

	//Row 2
	Hj(1, 0) = -py / diag_2;
	Hj(1, 1) = px / diag_2;
	Hj(1, 2) = 0;
	Hj(1, 3) = 0;

	//Row 3	
	Hj(2, 0) = py * (vx * py - vy * px) / g_3_2;
	Hj(2, 1) = py * (vy * px - vx * py) / g_3_2;
	Hj(2, 2) = px / g;
	Hj(2, 3) = py / g;


	return Hj;
}