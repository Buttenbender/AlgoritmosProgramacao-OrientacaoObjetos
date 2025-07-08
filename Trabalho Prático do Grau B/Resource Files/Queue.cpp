#include "Queue.h"

Queue::Node::Node(Process* d)
	: data(d), next(nullptr) { }

Queue::Queue()
	: front(nullptr), rear(nullptr), count(0) { }

Queue::~Queue() {
	while (!empty()) {
		dequeue();
	}
}

void Queue::enqueue(Process* d) {
	Node* newNode = new Node(d);
	if (empty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
	count++;
}

Process* Queue::dequeue() {
	if (empty()) {
		cerr << "Error: Empty Queue!" << endl;
		return nullptr;
	}
	Node* temp = front;
	Process* data = temp->data;
	front = front->next;
	delete temp;
	count--;

	if (empty()) {
		rear = nullptr;
	}
	return data;
}

Process* Queue::peek() const {
	if (empty()) {
		cerr << "Error: Empty Queue!" << endl;
		return nullptr;
	}
	return front->data;
}

bool Queue::empty() const {
	return (front == nullptr);
}

int Queue::size() const {
	return count;
}