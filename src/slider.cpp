#include "../include/slider.h"

Slider::Slider()
{
    // Use default values
    const double vals[2] = {DEF_MIN_VAL, DEF_MAX_VAL};
    const double degs[2] = {DEF_MIN_DEGREES, DEF_MAX_DEGREES};
    SetRanges(vals, degs);
}

Slider::Slider(const double in_range[2], const double map_range[2])
{
    SetRanges(in_range, map_range);
}

Slider::~Slider()
{
}

void Slider::SetRanges(const double in_range[2], const double map_range[2])
{
    input_range[0] = in_range[0];
    input_range[1] = in_range[1];

    mapped_range[0] = map_range[0];
    mapped_range[1] = map_range[1];
}

void Slider::SetValue(const double val)
{
    // USE FOR DEBUG ONLY
    value = val;
}

double Slider::GetValue()
{
    // TODO: implement with gpio
    return value;
}

double Slider::GetMappedValue()
{
    double input_range_span = input_range[1] - input_range[0];
    double percent_across = GetValue()/input_range_span;
    
    return mapped_range[0] + (mapped_range[1] - mapped_range[0])*percent_across;
}



