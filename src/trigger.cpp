#include "../include/trigger.h"
#include <thread>
#include <iostream>

Trigger::Trigger()
{
}

Trigger::~Trigger()
{
}

void Trigger::Listen(std::function<void()> callback)
{
    // dispatch a new thread
    std::thread t = std::thread([&]
    {
        int counter = 0;
        while(true)
        {
            // sleep a bit
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            std::cout << "Counter is: " << counter << std::endl;

            // TODO: change to rising edge check on pi
            if(counter % 50 == 0)
            {
                // Do the thing that the callee wants
                std::cout << "CALLING THE CALLBACK\n";
                callback();
            }
            counter++;
        }
    });

    t.join();
    
    // inside that thread, check for rising edge or whatever within a loop

}

void Trigger::SetDebugCondition(bool cond)
{
    _debug_condition = cond;
}

