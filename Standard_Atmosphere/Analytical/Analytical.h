#ifndef ANALYTICAL_H
#define ANALYTICAL_H

class Atmosphere_Analytical
{   
    private:
        // Any variables you might need
        // Recall then geopotential altitude is different from geometric altitude

    public:
        double getTemperature(double geometric_altitude);
        double getPressure(double geometric_altitude);
        double getDensity(double geometric_altitude);   
};

#endif
