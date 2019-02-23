#include <iostream>
#include <memory>
#include <thread>
#include "../include/player.h"
#include "../include/rocker.h"
#include "../include/slider.h"
#include "../include/trigger.h"
#include "../include/gps_interface.h"
#include "../include/gps_coordinates.h"


using namespace std;

int main() 
{
    // // Testing GPS class
    // std::shared_ptr<Rocker> e_w_rocker = std::make_shared<Rocker>(GPS::EAST, GPS::WEST);
    // std::shared_ptr<Slider> e_w_slider = std::make_shared<Slider>();
    // std::shared_ptr<Rocker> n_s_rocker = std::make_shared<Rocker>(GPS::NORTH, GPS::SOUTH);
    // std::shared_ptr<Slider> n_s_slider = std::make_shared<Slider>();

    // GPS::GPSCoordinates correct_coords;

    // // Current Defaults
    // correct_coords.lat_label = GPS::EAST;
    // correct_coords.long_label = GPS::NORTH;
    // correct_coords.latitude = 0.0;
    // correct_coords.longitude = 0.0;

    // //GPS::GPSInterface gps_int(rocker, rocker, slider, slider, correct_coords);
    // std::shared_ptr<GPS::GPSInterface> gps_int = std::make_shared<GPS::GPSInterface>(
    //     e_w_rocker,
    //     n_s_rocker,
    //     e_w_slider,
    //     n_s_slider, correct_coords);

    // gps_int->PrintCoords(gps_int->GetCurrentCoords());

    // Create the Trigger object
    std::shared_ptr<Trigger> trigger = std::make_shared<Trigger>();

    std::function<void()>lambda = [] () -> int
    {
        std::cout << "I'm going to check the gps coordinates now...";
        return 0;
    };

    std::cout << "About to set trigger...\n";
    trigger->Listen(lambda);
    std::cout << "Trigger set! Waiting 5 seconds.\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));

    trigger->SetDebugCondition(true);


    return 0;
}
