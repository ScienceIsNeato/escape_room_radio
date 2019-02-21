#ifndef GPS_COORDINATES_H
#define GPS_COORDINATES_H

namespace GPS{

    const std::string NORTH = "N";
    const std::string SOUTH = "S";
    const std::string EAST = "E";
    const std::string WEST = "W";

    struct GPSCoordinates
    {
        std::string lat_label; // One of 'N' -> True, 'S' -> False
        std::string long_label;  // One of 'E' -> True, 'W' -> False
        double latitude;
        double longitude;
    };
}

#endif