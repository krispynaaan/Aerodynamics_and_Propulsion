//#include "panel_method.h" //for some reason including the header file created typing issues in the header file
                            //for the time being, it is unnecessary and commented out
#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <math.h>

using std::vector;

vector<vector<double>> cpg(vector<vector<double>> points)
{
    size_t numPoints = points.size(); // number of points i.e. number of rows

    vector<vector<double>> cpt(numPoints, vector<double>(2)); // makes an array, cpt, the same size as points

    for (size_t i = 0; i < numPoints; i++)
    {
        if (i == numPoints - 1)
        {
            cpt[i][0] = (points[0][0] + points[i][0]) / 2;
            cpt[i][1] = (points[0][1] + points[i][1]) / 2;
        }
        else
        {
            for (int j = 0; j < 2; j++)
            {
                cpt[i][j] = (points[i + 1][j] + points[i][j]) / 2;
            }
        }
    }
    return cpt;
}

vector<vector<double>> phi_S_generator(vector<vector<double>> points)
{
    size_t numPoints = points.size();

    vector<vector<double>> phi_S(numPoints, vector<double>(2));

    double dx, dy;
    double pi = 2 * acos(0.0);

    for(size_t i = 0; i < numPoints; i++)
    {
        if (i == numPoints - 1)
        {
            dx = points[0][0] - points[i][0];
            dy = points[0][1] - points[i][1];
        }
        else
        {
            dx = points[i + 1][0] - points[i][0];
            dy = points[i + 1][1] - points[i][1];
        }
        phi_S[i][0] = pow(pow(dx,2)+pow(dy,2), 0.5);
        phi_S[i][1] = atan2(dy,dx);
        if (phi_S[i][0] < 0) phi_S[i][0] = phi_S[i][0] + 2 * pi;
    }
    return phi_S;
}

vector<vector<vector<double>>> ij_spm(vector<vector<double>> cpt, vector<vector<double>> points, vector<vector<double>> phi_S)
{
    size_t numPanels = points.size();
    vector<vector<double>> I(numPanels, vector<double>(numPanels));
    vector<vector<double>> J(numPanels, vector<double>(numPanels));

    for (size_t i = 0; i < numPanels; i++){
        for (size_t j = 0; j < numPanels; j++){
            if (j != i)
            {   
                double A = -(cpt[i][0] - points[j][0]) * cos(phi_S[j][0]) - (cpt[i][1] - points[j][1]) * sin(phi_S[j][0]);
                double B = pow((cpt[i][0] - points[j][0]),2) + pow((cpt[i][1] - points[j][1]),2);
                double Cn = sin(phi_S[i][0] - phi_S[j][0]);
                double Dn = -(cpt[i][0] - points[j][0]) * sin(phi_S[i][0]) + (cpt[i][1] - points[j][1]) * cos(phi_S[i][0]);
                double Ct = -cos(phi_S[i][0] - phi_S[j][0]);
                double Dt = (cpt[i][0] - points[j][0]) * cos(phi_S[i][0]) + (cpt[i][1] - points[j][1]) * sin(phi_S[i][0]);
                double E;
                if (B - pow(A,2) < 0) E = 0;
                else E = sqrt(B - pow(A,2));
                double term1 = 0.5 * Cn * log((pow(phi_S[j][1],2) + 2 * A * phi_S[j][1] + B) / B);
                double term2 = ((Dn - A * Cn) / E) * (atan2((phi_S[j][1] + A),E) - atan2(A,E));
                I[i][j] = term1 + term2;
                term1 = 0.5 * Ct * log((pow(phi_S[j][1],2) + 2 * A * phi_S[j][1] + B) / B);
                term2 = ((Dt - A * Ct) / E) * (atan2((phi_S[j][1] + A), E) - atan2(A, E));
                J[i][j] = term1 + term2;
            }
            if(isnan(I[i][j])) I[i][j] = 0;
            if(isnan(J[i][j])) J[i][j] = 0;
        }
    }
    return {I,J};
}

void Points2File(vector<vector<double>> points, std::string filename)
{
    std::ofstream file;
    file.open(filename);
    file << "x or phi, y or S"
         << "\n";
    for (size_t i = 0; i < points.size(); i++)
    {
        file << points[i][0] << "," << points[i][1] << "\n";
    }
    file.close();
}

void Points2FileIJ(vector<vector<double>> points, std::string filename)
{
    std::ofstream file;
    file.open(filename);
    size_t numPoints = points.size();
    for (size_t i = 0; i < numPoints; i++){
        for (size_t j = 0; j < numPoints; j++){
            if (j == numPoints - 1) file << points[i][j];
            else file << points[i][j] << ",";
        }
            file << "\n";
    }
    file.close();
}