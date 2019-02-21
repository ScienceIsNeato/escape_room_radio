#ifndef GPS_INTERFACE_H
#define GPS_INTERFACE_H

#include <memory>
#include "slider.h"
#include "rocker.h"
#include "gps_coordinates.h"

namespace GPS
{
    class GPSInterface
    {
    private:
        GPS::GPSCoordinates _correct_coords;
        std::shared_ptr<Rocker> _N_S_rocker;
        std::shared_ptr<Rocker> _E_W_rocker;
        std::shared_ptr<Slider> _N_S_slider;
        std::shared_ptr<Slider> _E_W_slider;

    public:
        GPSInterface(   std::shared_ptr<Rocker> N_S_rocker,
                        std::shared_ptr<Rocker>  E_W_rocker,
                        std::shared_ptr<Slider>  N_S_slider,
                        std::shared_ptr<Slider>  E_W_slider,
                        GPS::GPSCoordinates correct_coords
        );

        ~GPSInterface();

        void SetCorrectCoords(GPS::GPSCoordinates coords);
        void PrintCoords(GPS::GPSCoordinates coords);
        bool CoordsCorrect(GPS::GPSCoordinates coords);
        GPS::GPSCoordinates GetCurrentCoords();
    };
}

#endif