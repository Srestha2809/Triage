#include "Ailment.h"

Ailment::Ailment() : 
    name_(), severity_(0), time_sensitivity_(0), contagiousness_(0)
{
}

Ailment::Ailment(const std::string& name, int severity, int time_sensitivity, int contagiousness) :
    name_(name), severity_(severity), time_sensitivity_(time_sensitivity), contagiousness_(contagiousness)
{
}

std::string Ailment::get_name()
{
    return name_;
}

int Ailment::get_severity()
{
    return severity_;
}

int Ailment::get_time_sensitivity()
{
    return time_sensitivity_;
}

int Ailment::get_contagiousness()
{
    return contagiousness_;
}

bool Ailment::operator==(const Ailment& ailment) const
{
    // Check all the parts for equality
    return ailment.name_ == name_ && ailment.severity_ == severity_
        && ailment.time_sensitivity_ == time_sensitivity_ && ailment.contagiousness_ == contagiousness_;
}

bool Ailment::operator!=(const Ailment& ailment) const
{
    // Do the == operation and negate it
    return !(*this == ailment);
}