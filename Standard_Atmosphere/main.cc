#include <iostream>

// Inlcudes both atmosphere models
#include "Table/Table.h"
#include "Analytical/Analytical.h"

int main(){
    Atmosphere_Table standard_atmosphere_table;
    Atmosphere_Analytical standard_atmosphere_analytical;
    
    double test_altitudes[] = {0.0, 1000.0, 2000.0, 3000.0, 4000.0, 5000.0};
    


    // Basic Tests for Lookup Table Model
    std::cout << "Lookup Table Model" << std::endl;
    std::cout << "Geometric Altitude [m] | Temperature [K] | Pressure [Pa] | Density [kg/m^3]" << std::endl;
    for(int i = 0; i < 6; i++){
        std::cout << test_altitudes[i] << " | " << standard_atmosphere_table.getTemperature(test_altitudes[i]) << " | " << standard_atmosphere_table.getPressure(test_altitudes[i]) << " | " << standard_atmosphere_table.getDensity(test_altitudes[i]) << std::endl;
    }

    std::cout << std::endl;

    //Basic Tests for Analytical Model
    std::cout << "Analytical Model" << std::endl;
    std::cout << "Geometric Altitude [m] | Temperature [K] | Pressure [Pa] | Density [kg/m^3]" << std::endl;
    for(int i = 0; i < 6; i++){
        std::cout << test_altitudes[i] << " | " << standard_atmosphere_analytical.getTemperature(test_altitudes[i]) << " | " << standard_atmosphere_analytical.getPressure(test_altitudes[i]) << " | " << standard_atmosphere_analytical.getDensity(test_altitudes[i]) << std::endl;
    }




}