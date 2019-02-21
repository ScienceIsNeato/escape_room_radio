#include "../include/gps_interface.h"
#include <iostream>
#include <math.h>

namespace GPS
{
    GPSInterface::GPSInterface( std::shared_ptr<Rocker> N_S_rocker,
                                std::shared_ptr<Rocker> E_W_rocker,
                                std::shared_ptr<Slider> N_S_slider,
                                std::shared_ptr<Slider> E_W_slider,
                                GPS::GPSCoordinates correct_coords)
    {
        _N_S_rocker = N_S_rocker;
        _E_W_rocker = E_W_rocker;
        _N_S_slider = N_S_slider;
        _E_W_slider = E_W_slider;
        _correct_coords = correct_coords;
    }

    GPSInterface::~GPSInterface()
    {
    }

    void GPSInterface::SetCorrectCoords(GPS::GPSCoordinates coords)
    {
        _correct_coords  = coords;
    }

    GPS::GPSCoordinates GPSInterface::GetCurrentCoords()
    {
        GPS::GPSCoordinates current_coords;

        current_coords.lat_label = _N_S_rocker->GetStringValue();
        current_coords.long_label = _E_W_rocker->GetStringValue();
        current_coords.latitude = _N_S_slider->GetMappedValue();
        current_coords.longitude = _E_W_slider->GetMappedValue();
        return current_coords;
    }

    void GPSInterface::SetTolerance(double tolerance)
    {
        _tolerance = tolerance;
    }

    double GPSInterface::GetTolerance()
    {
        return _tolerance;
    }

    void GPSInterface::PrintCoords(GPS::GPSCoordinates coords)
    {
        std::cout << "Coordinates: " << 
        _N_S_slider->GetMappedValue() << " degress " <<
        _N_S_rocker->GetStringValue() << ", " <<
        _E_W_slider->GetMappedValue() << " degress " <<
        _E_W_rocker->GetStringValue() << std::endl;
    }

    bool GPSInterface::CoordsCorrect(GPS::GPSCoordinates coords)
    {
        bool ret_val = true;

        if(coords.lat_label != _correct_coords.lat_label)
        {
            ret_val = false;
        }
        if(coords.long_label != _correct_coords.long_label)
        {
            ret_val = false;
        }
        if(fabs(coords.latitude - _correct_coords.latitude) > _tolerance)
        {
            ret_val = false;
        }
        if(fabs(coords.longitude != _correct_coords.longitude) > _tolerance)
        {
            ret_val = false;
        }

        std::cout << "Correct coordinates is " << ret_val << ".\n";
        return ret_val;
    }
}