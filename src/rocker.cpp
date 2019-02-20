#include "../include/rocker.h"

Rocker::Rocker()
{
    SetOffString("OFF");
    SetOnString("ON");
}

Rocker::Rocker(std::string off_str, std::string on_str)
{
    SetOffString(off_str);
    SetOnString(on_str);
}

Rocker::~Rocker()
{
}

bool Rocker::GetRawValue()
{
    // TODO: Implement with gpio
    return 0;
}

std::string Rocker::GetOnString()
{
    return on_str;
}

std::string Rocker::GetOffString()
{
    return off_str;
}

std::string Rocker::GetStringValue()
{
    return GetRawValue() ? GetOnString() : GetOffString();
}

void Rocker::SetOnString(std::string val)
{
    on_str = val;
}

void Rocker::SetOffString(std::string val)
{
    off_str = val;
}
