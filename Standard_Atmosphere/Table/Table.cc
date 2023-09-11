#include "Table.h"
#include "iostream"
using namespace std;

int main(){
    Atmosphere_Table atmosTable;
    cout << "\nChoose an altitude you'd like to inspect in meters\n\n";
    double x;
    cin >> x;
    cout << "\nTemperature:   " << atmosTable.getTemperature(x) << " K";
    cout << "\nPressure:      " << atmosTable.getPressure(x) << " N/(m^2)";
    cout << "\nDensity:       " << atmosTable.getDensity(x) << " kg/(m^3)\n\n";
}

double Atmosphere_Table::getTemperature(double geometric_altitude){
    double temperature = interpolate(geometric_altitude, 1);
    return temperature;
}

double Atmosphere_Table::getPressure(double geometric_altitude){
    double pressure = interpolate(geometric_altitude, 2);
    return pressure;
}

double Atmosphere_Table::getDensity(double geometric_altitude){
    double density = interpolate(geometric_altitude, 3);
    return density;
}

double Atmosphere_Table::interpolate(double x, int column){

    int rows = sizeof data/sizeof data[0];

    if (x < data[0][0] || x > data[rows-1][0]){
        cout << "ALTITUDE NOT IN GIVEN RANGE (RETURN 1) ";
        return 1;
    }

    double y;
    int l = 0, r = rows, m = 0;
    while (l < r){
        m = (l+r)/2;
        if (data[m][0] == x){
            y = data[m][column];
            return y;
        }
        if (x < data[m][0]){
            if (m > 0 && x > data[m-1][0]){
                y = (x-data[m-1][0])*(data[m][column]-data[m-1][column])/(data[m][0]-data[m-1][0])+data[m-1][column];
                return y;
            }
            r = m;
        }
        else {
            if (m < rows-1 && x < data[m+1][0]){
                y = (x-data[m-1][0])*(data[m][column]-data[m-1][column])/(data[m][0]-data[m-1][0])+data[m-1][column];
                return y;
            }
            l = m+1;
        }
    }

    cout << "\n!!!REACHED END OF INTERPOLATE FUNCTIONS INCORRECTLY (RETURN 1)!!!\n";
    return 1;

}