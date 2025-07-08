#include "Process.h"

Process::Process(int id)
	: id(id) {
}

int Process::getId() const {
	return id;
}