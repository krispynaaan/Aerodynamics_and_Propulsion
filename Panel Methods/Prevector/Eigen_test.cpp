#include <iostream>
#include <Eigen/Dense>
using namespace std;

using Eigen::MatrixXd;
using Eigen::VectorXd;

int main()
{
	 MatrixXd m = MatrixXd::Random(3,3);
       m = (m + MatrixXd::Constant(3,3,2.2)) * 40;
	 cout << "m =" << endl << m << endl;
	   VectorXd v(3);
	   v << 1, 2, 3;
	 cout << "m * v =" << endl << m * v << endl;
}