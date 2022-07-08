#pragma once
#include "Ailment.h"
#include "LinkedList.h"
#include <string>
#include <iostream>

class Patient
{
	std::string name_;
	LinkedList<Ailment> ailments_;

public:
	// Constructors
	Patient();
	Patient(const std::string& name);

	// Ailment functions
	void add_ailment(const Ailment& ailment);

	// Getter functions
	std::string get_name() const;
	const LinkedList<Ailment>& get_ailments() const;
	int get_score() const;

	// Operators
	bool operator==(const Patient& patient) const;
};

// Print the patient details on the output stream
std::ostream& operator<< (std::ostream& os, const Patient& patient);
