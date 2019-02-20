#include <iostream>
#include "../../include/player.h"
#include "../../include/rocker.h"
#include "../../include/slider.h"


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


    return 0;
}
