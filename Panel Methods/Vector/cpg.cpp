#include <iostream>
#include <vector>
#include <fstream>

using std::vector;

vector<vector<double>> cpg(vector<vector<double>> points){
    size_t numPoints = points.size(); // number of points i.e. number of rows

    vector<vector<double>> cpt(numPoints, vector<double>(2)); // makes an array, cpt, the same size as points

    for(size_t i = 0; i < numPoints; i++){
        if(i == numPoints - 1){
            cpt[i][0] = (points[0][0] + points[i][0]) / 2;
            cpt[i][1] = (points[0][1] + points[i][1]) / 2;
        }
        else{
            for(int j = 0; j < 2; j++){
                cpt[i][j] = (points[i+1][j] + points[i][j]) / 2;                
            }
        }
    }
    return cpt;
}

void Points2File(vector<vector<double>> points, std::string filename){
    std::ofstream file;
    file.open(filename);
    file << "x,y" << "\n";
    for(size_t i = 0; i < points.size(); i++){
        file << points[i][0] << "," << points[i][1] << "\n";
    }
    file.close();
}

int main(){
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
        {1.0000, -0.0013}
    };

    vector<vector<double>> cpt = cpg(points); // modifies cpt (control point table) to have needed values cp values
    Points2File(points, "points.txt");
    Points2File(cpt, "cpt.txt");
    
}