#pragma once
#include "Process.h"
#include "Queue.h"
#include "ComputingProcess.h"

class ReadingProcess : public Process {
public:
	ReadingProcess(int id);
	void loadFromFile(Queue& queue, int& nextId);
	void execute() override;
};
