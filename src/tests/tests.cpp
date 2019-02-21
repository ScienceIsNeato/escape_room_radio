#include <iostream>
#include <memory>
#include "../../include/player.h"
#include "../../include/rocker.h"
#include "../../include/slider.h"
#include "../../include/gps_interface.h"
#include "../../include/gps_coordinates.h"


using namespace std;

int main() 
{
    /* 
    // Testing the player class
    Player player;
    cout << "About to call correct...";
    player.play_audio(true);

    cout << "About to call incorrect...";
    player.play_audio(false);
    */

    /*
    // Testing the rocker class
    Rocker ew_rocker("East", "West");
    Rocker ns_rocker("North", "South");
    Rocker def_rocker;

    cout << "E/W Rocker is... " << ew_rocker.GetStringValue() << std::endl;
    cout << "N/S Rocker is... " << ns_rocker.GetStringValue() << std::endl;
    cout << "E/W Rocker is... " << def_rocker.GetStringValue() << std::endl;
    */

    // Testing the slider class
    Slider default_slider;
    cout << "Default slider mapped value should be 0 -  is... " << default_slider.GetMappedValue() << std::endl;
    default_slider.SetValue(255);
    cout << "Default slider mapped value should be 90 -  is... " << default_slider.GetMappedValue() << std::endl;
    default_slider.SetValue(128);
    cout << "Default slider mapped value should be 45 -  is... " << default_slider.GetMappedValue() << std::endl;

    Slider tweaked_slider((double[2]) {0,1000}, (double[2]) {0, 180});
    cout << "Default slider mapped value should be 0 -  is... " << tweaked_slider.GetMappedValue() << std::endl;
    tweaked_slider.SetValue(1000);
    cout << "Default slider mapped value should be 180 -  is... " << tweaked_slider.GetMappedValue() << std::endl;
    tweaked_slider.SetValue(500);
    cout << "Default slider mapped value should be 90 -  is... " << tweaked_slider.GetMappedValue() << std::endl;


    /************* Testing GPS class *******************/
    std::shared_ptr<Rocker> e_w_rocker = std::make_shared<Rocker>(GPS::EAST, GPS::WEST);
    std::shared_ptr<Slider> e_w_slider = std::make_shared<Slider>();
    std::shared_ptr<Rocker> n_s_rocker = std::make_shared<Rocker>(GPS::NORTH, GPS::SOUTH);
    std::shared_ptr<Slider> n_s_slider = std::make_shared<Slider>();

    GPS::GPSCoordinates correct_coords;

    // Current Defaults
    correct_coords.lat_label = GPS::EAST;
    correct_coords.long_label = GPS::NORTH;
    correct_coords.latitude = 0.0;
    correct_coords.longitude = 0.0;

    //GPS::GPSInterface gps_int(rocker, rocker, slider, slider, correct_coords);
    std::shared_ptr<GPS::GPSInterface> gps_int = std::make_shared<GPS::GPSInterface>(
        e_w_rocker,
        n_s_rocker,
        e_w_slider,
        n_s_slider, correct_coords);

    gps_int->SetTolerance(0);
    gps_int->PrintCoords(gps_int->GetCurrentCoords());

    assert(gps_int->CoordsCorrect(gps_int->GetCurrentCoords()) == true);
    std::cout << "Passed Test 1...\n";

    // East Wrong
    correct_coords.lat_label = GPS::WEST;
    correct_coords.long_label = GPS::NORTH;
    correct_coords.latitude = 0.0;
    correct_coords.longitude = 0.0;
    gps_int->SetCorrectCoords(correct_coords);
    assert(gps_int->CoordsCorrect(gps_int->GetCurrentCoords()) == false);
    std::cout << "GPS::Passed Test 2...\n";

    // North Wrong
    correct_coords.lat_label = GPS::EAST;
    correct_coords.long_label = GPS::SOUTH;
    correct_coords.latitude = 0.0;
    correct_coords.longitude = 0.0;
    gps_int->SetCorrectCoords(correct_coords);
    assert(gps_int->CoordsCorrect(gps_int->GetCurrentCoords()) == false);
    std::cout << "GPS::Passed Test 3...\n";

    // Lat Wrong
    correct_coords.lat_label = GPS::EAST;
    correct_coords.long_label = GPS::NORTH;
    correct_coords.latitude = 0.1;
    correct_coords.longitude = 0.0;
    gps_int->SetCorrectCoords(correct_coords);
    assert(gps_int->CoordsCorrect(gps_int->GetCurrentCoords()) == false);
    std::cout << "GPS::Passed Test 4...\n";

    // Long Wrong
    correct_coords.lat_label = GPS::EAST;
    correct_coords.long_label = GPS::NORTH;
    correct_coords.latitude = 0.0;
    correct_coords.longitude = 0.1;
    gps_int->SetCorrectCoords(correct_coords);
    assert(gps_int->CoordsCorrect(gps_int->GetCurrentCoords()) == false);
    std::cout << "GPS::Passed Test 5...\n";

    // Tolerance obeyed
    gps_int->SetTolerance(5.0);
    correct_coords.lat_label = GPS::EAST;
    correct_coords.long_label = GPS::NORTH;
    correct_coords.latitude = 0.0 + gps_int->GetTolerance();
    correct_coords.longitude = 0.0 + gps_int->GetTolerance();
    gps_int->SetCorrectCoords(correct_coords);
    assert(gps_int->CoordsCorrect(gps_int->GetCurrentCoords()) == true);
    std::cout << "GPS::Passed Test 6...\n";

    return 0;
}
