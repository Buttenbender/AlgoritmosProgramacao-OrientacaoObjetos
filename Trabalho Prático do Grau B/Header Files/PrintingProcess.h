#pragma once
#include "Process.h"
#include "Queue.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"

class PrintingProcess :public Process {
public:
	PrintingProcess(int id);
	void printProcessPool(Queue& queue);
	void execute() override;
};
