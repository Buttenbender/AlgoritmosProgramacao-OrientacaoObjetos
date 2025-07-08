#pragma once
#include "Process.h"

class Queue {
private:
	struct Node {
		Process* data;
		Node* next;
		Node(Process* d);
	};

	Node* front;
	Node* rear;
	int count;
public:
	Queue();
	~Queue();

	void enqueue(Process* d);
	Process* dequeue();
	Process* peek() const;
	bool empty() const;
	int size() const;
};
