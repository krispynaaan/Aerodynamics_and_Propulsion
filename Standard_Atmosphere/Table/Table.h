#ifndef TABLE_H
#define TABLE_H

class Atmosphere_Table
{   
    private:
        // Any variables you might need
        // HINT: 2D to store the data and extropolate
    public:
        double getTemperature(double geometric_altitude);
        double getPressure(double geometric_altitude);
        double getDensity(double geometric_altitude);   
};

#endif