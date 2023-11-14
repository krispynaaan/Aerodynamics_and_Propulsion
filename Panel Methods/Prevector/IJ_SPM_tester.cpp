#include "control_point_generator.cpp"
#include "IJ_SPM.cpp"
#include <iostream>
using namespace std;

int main(){

    double points[3][2] = {{1, 2}, {2, 4}, {3, 6}}; // example of list of 2-D points

    int numPoints = sizeof(points) / sizeof(points[0]); // number of points i.e. number of rows

    print(points, numPoints, 2); // prints points array

    double cpt[numPoints][2]; // makes an array, cpt, the same size as points

    cpg(cpt, points, numPoints, 2); // modifies cpt (control point table) to have needed values cp values

    print(cpt, numPoints, 2); // prints cpt

    double phi[numPoints][1]; 

    double S[numPoints][1];

    for(int i = 0; i < numPoints; i++){
        double dx = (*(*(points)+i)) - (*(*(points)+i));
        double dy = (*(*(points+1)+i)) - (*(*(points+1)+i));
        *(*(S)+i) = sqrt(pow(dx,2)+pow(dy,2));
        *(*(phi)+i) = atan2(dy,dx);
        if((*(*phi)+i) < 0) *(*(phi)+i) = *(*(phi)+i) + (4*acos(0));
    }

    double I[numPoints][numPoints];

    double J[numPoints][numPoints];

    ijSPM(numPoints, phi, S, points, cpt, I, J);

    //print(I, numPoints, numPoints);

    //print(J, numPoints, numPoints);

}