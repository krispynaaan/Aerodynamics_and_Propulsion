#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

void ijSPM(int numPan, double(*phi)[1], double(*S)[1], double(*BPA)[2], double(*CPA)[2], double(*I)[2], double(*J)[2]){

    // numPan - number of panels
    // phi - angle between positive x-axis and interior of panel
    // S - length of panel
    // BPA - boundary point arrays
    // CPA - control point arrays
    // I - value of panel-normal integral
    // J - value of panel-tangential integral

    int i,j;
    for(i = 0; i < numPan; i++){
        for(j = 0; j < numPan; j++){

            if(j != i){

                double A = -((*(*(CPA)+i)) - (*(*(BPA)+j))) * cos(*(*(phi)+j)) - ((*(*(CPA+1)+1)) - (*(*(BPA+1)+j))) * sin(*(*(phi)+j));
                double B = pow(((*(*(CPA) + i)) - (*(*(BPA) + j))), 2) - pow(((*(*(CPA + 1) + 1)) - (*(*(BPA + 1) + j))), 2);
                double Cn = sin((*(*(phi)+i)) - (*(*(phi)+j)));
                double Dn = -((*(*(CPA) + i)) - (*(*(BPA) + j))) * sin(*(*(phi) + i)) - ((*(*(CPA + 1) + 1)) - (*(*(BPA + 1) + j))) * cos(*(*(phi) + i));
                double Ct = -cos((*(*(phi) + i)) - (*(*(phi) + j)));
                double Dt = -((*(*(CPA) + i)) - (*(*(BPA) + j))) * cos(*(*(phi) + i)) - ((*(*(CPA + 1) + 1)) - (*(*(BPA + 1) + j))) * sin(*(*(phi) + i));
                double E;
                if(B-pow(A,2) < 0) E = 0;
                else E = sqrt(B-pow(A,2));

                double term1 = 0.5 * Cn * log((pow((*(*(S) + j)), 2) + 2 * A * (*(*(S) + j)) + B) / B);
                double term2 = ((Dn-A*Cn)/E) * (atan2(((*(*(S)+j))+A),E) - atan2(A,E));
                *(*(I + i) + j) = term1 + term2;

                term1 = 0.5 * Ct * log((pow((*(*(S) + j)), 2) + 2 * A * (*(*(S) + j)) + B) / B);
                term2 = ((Dt - A * Ct) / E) * (atan2(((*(*(S) + j)) + A), E) - atan2(A, E));
                *(*(J + i) + j) = term1 + term2;
            }

            if (isnan(*(*(I + i) + j))) *(*(I + i) + j) = 0;
            if (isnan(*(*(J + i) + j))) *(*(J + i) + j) = 0;
        }
    }

}