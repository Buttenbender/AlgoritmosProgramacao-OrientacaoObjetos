#pragma once
#include "Process.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include "Queue.h"

class System {
private:
	void printProcessPool(Queue& queue);
	void saveQueueToFile(Queue& queue, const string& fileName);
	void loadQueueFromFile(Queue& queue, int& nextId, const string& fileName);
public:
	void showMenu();
	void runProgram();
	void createProcess();
};