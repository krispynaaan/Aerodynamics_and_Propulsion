#include "panel_method.cpp" //can include .h instead but "panel_method.cpp" would need to be included during compilation
                            //see "cpg_tester.cpp" for reference
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <math.h>
using std::vector;

int main()
{
    std::vector<std::vector<double>> points = {
        {1.0000, 0.0013},
        {0.9500, 0.0114},
        {0.9000, 0.0208},
        {0.8000, 0.0375},
        {0.7000, 0.0518},
        {0.6000, 0.0636},
        {0.5000, 0.0724},
        {0.4000, 0.0780},
        {0.3000, 0.0788},
        {0.2500, 0.0767},
        {0.2000, 0.0726},
        {0.1500, 0.0661},
        {0.1000, 0.0563},
        {0.0750, 0.0496},
        {0.0500, 0.0413},
        {0.0250, 0.0299},
        {0.0125, 0.0215},
        {0.0000, 0.0000},
        {0.0125, -0.0165},
        {0.0250, -0.0227},
        {0.0500, -0.0301},
        {0.0750, -0.0346},
        {0.1000, -0.0375},
        {0.1500, -0.0410},
        {0.2000, -0.0423},
        {0.2500, -0.0422},
        {0.3000, -0.0412},
        {0.4000, -0.0380},
        {0.5000, -0.0334},
        {0.6000, -0.0276},
        {0.7000, -0.0214},
        {0.8000, -0.0150},
        {0.9000, -0.0082},
        {0.9500, -0.0048},
        {1.0000, -0.0013}};

    vector<vector<double>> cpt = cpg(points); // modifies cpt (control point table) to have needed values cp values
    vector<vector<double>> phi_S  = phi_S_generator(points);
    vector<vector<vector<double>>> ij = ij_spm(cpt, points, phi_S);
    Points2File(points, "points.txt");
    Points2File(cpt, "cpt.txt");
    Points2File(phi_S, "phi_S.txt");
    Points2FileIJ(ij[0],"i.txt");
    Points2FileIJ(ij[1],"j.txt");
}