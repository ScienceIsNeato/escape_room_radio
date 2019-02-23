#ifndef TRIGGER_H
#define TRIGGER_H

#include <functional>

class Trigger
{
    // This class manages a triggered event (i.e. button press) that initiates the checks throughout the program
    private:
        bool _debug_condition = false;
        
    public:
        Trigger();
        ~Trigger();
        void Listen(std::function<void()> callback);
        void SetDebugCondition(bool cond);
};

#endif