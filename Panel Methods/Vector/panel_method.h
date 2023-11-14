#ifndef PANEL_METHOD_H
#define PANEL_METHOD_H

    vector<vector<double>> cpg(vector<vector<double>> points);
    vector<vector<double>> phi_S_generator(vector<vector<double>> points);
    vector<vector<vector<double>>> ij_spm(vector<vector<double>> cpt, vector<vector<double>> points, vector<vector<double>> phi_S);
    void Points2File(vector<vector<double>> points, std::string filename);
    void Points2File(vector<vector<double>> points, std::string filename);

#endif