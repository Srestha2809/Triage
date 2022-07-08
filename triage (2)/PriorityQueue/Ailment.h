#pragma once

#include <string>

class Ailment
{
private:
    std::string name_;
    int severity_;
    int time_sensitivity_;
    int contagiousness_;

public:
    // Constructors
    Ailment();
    Ailment(const std::string& name, int severity, int time_sensitivity, int contagiousness);

    // Getter functions
    std::string get_name();
    int get_severity();
    int get_time_sensitivity();
    int get_contagiousness();

    // Comparison operator
    bool operator==(const Ailment& ailment) const;
    bool operator!=(const Ailment& ailment) const;
    
};
