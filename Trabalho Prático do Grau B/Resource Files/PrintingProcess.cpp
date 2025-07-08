#include "PrintingProcess.h"

PrintingProcess::PrintingProcess(int id)
    : Process(id) {
}

void PrintingProcess::printProcessPool(Queue& queue) {
    if (queue.empty()) {
        cout << "\nThe queue is empty!" << endl;
        return;
    }

    cout << "\n===========================================\n";
    cout << "           CURRENT PROCESS POOL         \n";
    cout << "===========================================\n";

    Queue tempQueue;
    int originalSize = queue.size();

    for (int i = 0; i < originalSize; i++) {
        Process* p = queue.dequeue();

        cout << "Process ID: " << p->getId();

        if (auto* cp = dynamic_cast<ComputingProcess<int>*>(p)) {
            cout << " (ComputingProcess<int>)";
            cout << " Expression: " << cp->getExpression();
        }
        else if (auto* cp = dynamic_cast<ComputingProcess<float>*>(p)) {
            cout << " (ComputingProcess<float>)";
            cout << " Expression: " << cp->getExpression();
        }
        else if (auto* cp = dynamic_cast<ComputingProcess<double>*>(p)) {
            cout << " (ComputingProcess<double>)";
            cout << " Expression: " << cp->getExpression();
        }
        else if (auto* wp = dynamic_cast<WritingProcess<int>*>(p)) {
            cout << " (WritingProcess<int>)";
            cout << " Expression: " << wp->getExpression();
        }
        else if (auto* wp = dynamic_cast<WritingProcess<float>*>(p)) {
            cout << " (WritingProcess<float>)";
            cout << " Expression: " << wp->getExpression();
        }
        else if (auto* wp = dynamic_cast<WritingProcess<double>*>(p)) {
            cout << " (WritingProcess<double>)";
            cout << " Expression: " << wp->getExpression();
        }
        else if (dynamic_cast<ReadingProcess*>(p)) {
            cout << " (ReadingProcess)";
        }
        else if (dynamic_cast<PrintingProcess*>(p)) {
            cout << " (PrintingProcess)";
        }

        cout << endl;
        tempQueue.enqueue(p);
    }

    while (!tempQueue.empty()) {
        queue.enqueue(tempQueue.dequeue());
    }

    cout << "===========================================\n";
    cout << "Total processes in queue: " << queue.size() << endl;
}

void PrintingProcess::execute() {
    cout << "\nPrinting Process " << getId() << " is ready to print the process pool!" << endl;
}