#include "control_point_generator.h"
#include <iostream>
using namespace std;

void print(double (*arr)[2], int row, int col){
    int i, j;
    for(i=0; i<row; i++){
        for(j=0; j<col; j++)
            cout << "\t" << *(*(arr+i)+j);
        cout << "\n";
    }
    cout << "\n";
}

void cpg(double (*cpt)[2], double (*originalPoints)[2], int row, int col){
    int i, j;
    for(i = 0; i<row; i++){
        if(i == row-1){
            *(*(cpt+i)) = (*(*(originalPoints)) + *(*(originalPoints+i))) / 2;
            *(*(cpt+i)+1) = (*(*(originalPoints)+1) + *(*(originalPoints+i)+j)) / 2;
        }
        else{
            for(j=0; j<col; j++){
                *(*(cpt+i)+j) = (*(*(originalPoints+i+1)+j) + *(*(originalPoints+i)+j)) / 2;                
            }
        }
    }
}