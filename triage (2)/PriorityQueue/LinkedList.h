#pragma once

template <typename T>
class LinkedList
{
public:
	struct Node
	{
		Node* previous;
		Node* next;

		T data;
	};

protected:
	Node* begin_;
	Node* end_;

public:
	LinkedList() : begin_(nullptr), end_(nullptr) {}

	Node* begin() const { return begin_; }
	Node* end() { return end_; }

	void push_front(const T& item)
	{
		Node* node = new Node();
		node->data = item;

		//check if there is a node to link in-front of
		if (begin_ != nullptr)
		{
			begin_->previous = node;
			node->next = begin_;
		}
		else
		{
			end_ = node;
		}

		begin_ = node;
	}

	void push_back(const T& item)
	{
		Node* node = new Node();
		node->data = item;

		if (begin_ == nullptr && end_ == nullptr)
		{
			begin_ = node;
			end_ = node;
			return;
		}

		node->previous = end_;
		end_->next = node;

		end_ = node;
	}

	T pop_front()
	{
		if (begin_ == nullptr)
		{
			//todo: throw
			throw "";
		}

		Node* node = begin_;
		const T value = node->data;
		begin_ = node->next;

		return value;
	}

	T pop_back()
	{
		if (end_ == nullptr)
		{
			//todo: throw
			throw "";
		}

		Node* node = end_;
		const T value = node->data;
		begin_ = node->previous;

		return value;
	}

	void insert(Node* insertionPoint, const T& item)
	{
		// If insertion point is null, push back the new item
		if (insertionPoint == nullptr)
		{
			push_back(item);
			return;
		}

		// Insert the new item before the insertPoint
		Node* node = new Node();
		node->data = item;

		// Set the links of the node
		node->next = insertionPoint;
		node->previous = insertionPoint->previous;

		// Link node to its previous node
		if (node->previous != nullptr)
			node->previous->next = node;
		else
			begin_ = node;

		// Link node to its next node
		node->next->previous = node;

		// Update size

	}

	bool empty() const
	{
		return begin_ == nullptr;
	}

	size_t size() const
	{
		size_t counter = 0;

		Node* node = begin_;
		while (node != nullptr)
		{
			++counter;
			node = node->next;
		}

		return counter;
	}
};
