#ifndef SLIDER_H
#define SLIDER_H

#include <string>

class Slider

{
private:
    
    const double DEF_MIN_VAL = 0;
    const double DEF_MAX_VAL = 255;
    const double DEF_MIN_DEGREES = 0.0;
    const double DEF_MAX_DEGREES = 90.0;

    double input_range[2];
    double mapped_range[2];
    double value = 0;

    void SetRanges(const double input_range[2], const double mapped_range[2]);


public:
    Slider();
    Slider(const double input_range[2], const double mapped_range[2]);
    ~Slider();

    double GetValue();
    double GetMappedValue();

    void SetValue(const double val); // DEBUG ONLY

};

#endif