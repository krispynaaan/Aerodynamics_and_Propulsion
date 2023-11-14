// Make sure to compile control_point_generator.cpp with this code
// i.e. you can use "g++ -o ./*cpp" to compile all cpp files in
// the current directory. Alternatively, you can replace 
// "#include "control_point_generator.h"" with
// "#include "control_point_generator.cpp"" and compile
// normally.

#include "control_point_generator.h"
#include <iostream>
using namespace std;

int main(){

    double points[3][2] = {{1,2},{2,4},{3,6}}; // example of list of 2-D points

    const int numPoints = sizeof(points)/sizeof(points[0]); // number of points i.e. number of rows

    print(points, numPoints, 2); // prints points array

    double cpt[numPoints][2]; // makes an array, cpt, the same size as points

    cpg(cpt, points, numPoints, 2); // modifies cpt (control point table) to have needed values cp values

    print(cpt, numPoints, 2); // prints cpt

}