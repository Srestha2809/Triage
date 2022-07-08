#pragma once


template <typename T>
class PriorityQueue
{
	LinkedList<T> patients_;

public:
	PriorityQueue() {}

	// Check if queue is empty
	bool empty() const
	{
		return patients_.empty();
	}

	// Get the size of the queue
	size_t size() const
	{
		return patients_.size();
	}

	// Add a new patient
	void enqueue(const T& patient)
	{
		// Find the correct spot for the patient's score
		int score = patient.get_score();

		// Check if linked list is empty
		if (patients_.empty())
		{
			patients_.push_front(patient);
			return;
		}

		// Find the insertion point based on score
		for (auto* node = patients_.begin(); node; node = node->next)
		{
			if (node->data.get_score() < score)
			{
				patients_.insert(node, patient);
				return;
			}
		}

		patients_.push_back(patient);
	}

	// Remove the first patient in the list
	T dequeue()
	{
		return patients_.pop_front();
	}

	// Get the patient on top of the list
	T peek()
	{
		return patients_.begin()->data;
	}

	// Get the pointer to the top of the list
	auto* begin()
	{
		return patients_.begin();
	}


};
