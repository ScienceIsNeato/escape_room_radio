#include <string>

class Rocker

{
private:
    /* data */
    std::string on_str;
    std::string off_str;

    void SetOnString(std::string);
    void SetOffString(std::string);

public:
    Rocker();
    Rocker(std::string off_str, std::string on_str);
    ~Rocker();

    bool GetRawValue();
    std::string GetStringValue();
    std::string GetOnString();
    std::string GetOffString();
};