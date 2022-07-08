#include "Patient.h"

// Constructor
Patient::Patient() : name_(), ailments_()
{
}

Patient::Patient(const std::string& name) : name_(name), ailments_()
{
}

// Ailment functions
void Patient::add_ailment(const Ailment& ailment)
{
    ailments_.push_back(ailment);
}

// Getter functions
std::string Patient::get_name() const
{
    return name_;
}

const LinkedList<Ailment>& Patient::get_ailments() const
{
    return ailments_;
}

int Patient::get_score() const
{
    int score = 0;

    // Loop through each ailment and compute the score for each
    // Add all the scores for each element
    for (auto* ailment = ailments_.begin(); ailment != nullptr; ailment = ailment->next)
    {
        score += ailment->data.get_severity() * ailment->data.get_time_sensitivity() + ailment->data.get_contagiousness();
    }

    return score;
}

bool Patient::operator==(const Patient& patient) const
{
    // Compare the name
    if (patient.name_ != name_)
        return false;

    // Compare the number of ailments
    if (patient.ailments_.size() != ailments_.size())
        return false;

    // Compare the ailments one-by-one
    for (auto* ailment1 = ailments_.begin(), *ailment2 = patient.ailments_.begin();
         ailment1 != nullptr;
         ailment1 = ailment1->next, ailment2 = ailment2->next)
    {
        if (ailment1->data != ailment2->data)
        {
            return false;
        }
    }

    return true;
}

std::ostream& operator<< (std::ostream& os, const Patient& patient)
{
    // Print name and score
    os << patient.get_name() << " - ";
    os << patient.get_score() << " - ";

    // Print ailments
    for (auto* ailment = patient.get_ailments().begin(); ailment; ailment = ailment->next)
    {
        os << ailment->data.get_name() << ", ";
    }

    return os;
}