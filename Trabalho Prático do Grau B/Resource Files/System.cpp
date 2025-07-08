#include "System.h"

void System::printProcessPool(Queue& queue) {
    PrintingProcess printer(0);
    printer.printProcessPool(queue);
}

void System::saveQueueToFile(Queue& queue, const string& fileName) {
    ofstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for writing: " << fileName << endl;
        return;
    }

    Queue tempQueue;
    while (!queue.empty()) {
        Process* p = queue.dequeue();
        tempQueue.enqueue(p);

        if (auto* cp = dynamic_cast<ComputingProcess<int>*>(p)) {
            file << "ComputingProcess<int> " << p->getId() << " " << cp->getExpression() << "\n";
        }
        else if (auto* cp = dynamic_cast<ComputingProcess<float>*>(p)) {
            file << "ComputingProcess<float> " << p->getId() << " " << cp->getExpression() << "\n";
        }
        else if (auto* cp = dynamic_cast<ComputingProcess<double>*>(p)) {
            file << "ComputingProcess<double> " << p->getId() << " " << cp->getExpression() << "\n";
        }
        else if (auto* wp = dynamic_cast<WritingProcess<int>*>(p)) {
            file << "WritingProcess<int> " << p->getId() << " " << wp->getExpression() << "\n";
        }
        else if (auto* wp = dynamic_cast<WritingProcess<float>*>(p)) {
            file << "WritingProcess<float> " << p->getId() << " " << wp->getExpression() << "\n";
        }
        else if (auto* wp = dynamic_cast<WritingProcess<double>*>(p)) {
            file << "WritingProcess<double> " << p->getId() << " " << wp->getExpression() << "\n";
        }
        else if (dynamic_cast<ReadingProcess*>(p)) {
            file << "ReadingProcess " << p->getId() << "\n";
        }
        else if (dynamic_cast<PrintingProcess*>(p)) {
            file << "PrintingProcess " << p->getId() << "\n";
        }
    }

    while (!tempQueue.empty()) {
        queue.enqueue(tempQueue.dequeue());
    }

    file.close();
    cout << "\nQueue saved to " << fileName << " successfully!" << endl;
}

void System::loadQueueFromFile(Queue& queue, int& nextId, const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file for reading: " << fileName << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string processType;
        int id;

        iss >> processType >> id;

        if (id >= nextId) {
            nextId = id + 1;
        }

        Process* p = nullptr;
        string expression;

        if (processType == "ComputingProcess<int>") {
            getline(iss, expression);
            expression.erase(0, expression.find_first_not_of(" \t"));
            p = new ComputingProcess<int>(id, expression);
        }
        else if (processType == "ComputingProcess<float>") {
            getline(iss, expression);
            expression.erase(0, expression.find_first_not_of(" \t"));
            p = new ComputingProcess<float>(id, expression);
        }
        else if (processType == "ComputingProcess<double>") {
            getline(iss, expression);
            expression.erase(0, expression.find_first_not_of(" \t"));
            p = new ComputingProcess<double>(id, expression);
        }
        else if (processType == "WritingProcess<int>") {
            getline(iss, expression);
            expression.erase(0, expression.find_first_not_of(" \t"));
            p = new WritingProcess<int>(id, expression);
        }
        else if (processType == "WritingProcess<float>") {
            getline(iss, expression);
            expression.erase(0, expression.find_first_not_of(" \t"));
            p = new WritingProcess<float>(id, expression);
        }
        else if (processType == "WritingProcess<double>") {
            getline(iss, expression);
            expression.erase(0, expression.find_first_not_of(" \t"));
            p = new WritingProcess<double>(id, expression);
        }
        else if (processType == "ReadingProcess") {
            p = new ReadingProcess(id);
        }
        else if (processType == "PrintingProcess") {
            p = new PrintingProcess(id);
        }

        if (p != nullptr) {
            queue.enqueue(p);
            cout << "Loaded process ID " << id << " (" << processType << ")";
            if (!expression.empty()) {
                cout << " with expression: " << expression;
            }
            cout << endl;
        }
    }

    file.close();
    cout << "\nQueue loaded from " << fileName << " successfully!" << endl;
}

void System::showMenu() {
    cout << "\n===========================================\n";
    cout << "            SYSTEM MAIN MENU         \n";
    cout << "===========================================\n";
    cout << "  [1] -> Create a new Process\n";
    cout << "  [2] -> Execute next Process in the queue\n";
    cout << "  [3] -> Execute a specific Process by ID\n";
    cout << "  [4] -> Save current Process queue to file\n";
    cout << "  [5] -> Load Process queue from file\n";
    cout << "  [0] -> EXIT\n";
    cout << "===========================================\n";
    cout << "  Choose an option: ";
}

void System::createProcess() {
    cout << "\n===========================================\n";
    cout << "           CREATE NEW PROCESS           \n";
    cout << "===========================================\n";
    cout << "   [1] -> Computing Process\n";
    cout << "   [2] -> Writing Process\n";
    cout << "   [3] -> Reading Process\n";
    cout << "   [4] -> Printing Process\n";
    cout << "   [0] -> RETURN\n";
    cout << "===========================================\n";
    cout << "  Choose an option: ";
}

void System::runProgram() {
    Queue queue;
    int nextId = 1;
    int opt;
    do {
        showMenu();
        cin >> opt;
        cin.ignore();

        switch (opt) {
        default:
            cout << "\nError: Invalid Option!\n";
            break;
        case 0:
            cout << "\nExiting Program...\n";
            break;
        case 1: {
            int choice;
            do {
                createProcess();
                cin >> choice;
                cin.ignore();

                switch (choice) {
                default:
                    cout << "\nError: Invalid Option!\n";
                    break;
                case 0:
                    break;
                case 1: {
                    string expression;
                    cout << "\nWrite the Expression: ";
                    getline(cin, expression);

                    Process* p = nullptr;

                    auto tryCreate = [&](auto typeTag) -> Process* {
                        using T = decltype(typeTag);
                        auto* temp = new ComputingProcess<T>(nextId, expression);
                        if (temp->validate()) return temp;
                        delete temp;
                        return nullptr;
                    };

                    if ((p = tryCreate(double{}))) {
                        queue.enqueue(p);
                        cout << "\nExpression '" << expression << "' enqueued as double process at ID " << nextId++ << "!" << endl;
                    }
                    else if ((p = tryCreate(float{}))) {
                        queue.enqueue(p);
                        cout << "\nExpression '" << expression << "' enqueued as float process at ID " << nextId++ << "!" << endl;
                    }
                    else if ((p = tryCreate(int{}))) {
                        queue.enqueue(p);
                        cout << "\nExpression '" << expression << "' enqueued as int process at ID " << nextId++ << "!" << endl;
                    }
                    else {
                        cerr << "\nError: Invalid expression for all numeric types!\n";
                    }
                    break;
                }
                case 2: {
                    string expression;
                    cout << "\nWrite the Expression: ";
                    getline(cin, expression);

                    Process* p = nullptr;

                    auto tryCreate = [&](auto typeTag) -> Process* {
                        using T = decltype(typeTag);
                        auto* temp = new WritingProcess<T>(nextId, expression);
                        if (temp->validate()) return temp;
                        delete temp;
                        return nullptr;
                        };

                    if ((p = tryCreate(double{}))) {
                        queue.enqueue(p);
                        cout << "\nExpression '" << expression << "' enqueued as double process at ID " << nextId++ << "!" << endl;
                    }
                    else if ((p = tryCreate(float{}))) {
                        queue.enqueue(p);
                        cout << "\nExpression '" << expression << "' enqueued as float process at ID " << nextId++ << "!" << endl;
                    }
                    else if ((p = tryCreate(int{}))) {
                        queue.enqueue(p);
                        cout << "\nExpression '" << expression << "' enqueued as int process at ID " << nextId++ << "!" << endl;
                    }
                    else {
                        cerr << "\nError: Invalid expression for all numeric types!\n";
                    }
                    break;
                }
                case 3: {
                    Process* p = new ReadingProcess(nextId++);
                    queue.enqueue(p);
                    cout << "\nReading Process enqueued at ID " << p->getId() << "!" << endl;
                    break;
                }
                case 4: {
                    Process* p = new PrintingProcess(nextId++);
                    queue.enqueue(p);
                    cout << "\nPrinting Process created with ID " << p->getId() << endl;
                    break;
                }
                }
            } while (choice != 0);
            break;
        }
        case 2: {
            if (!queue.empty()) {
                Process* p = queue.peek();
                cout << "\nExecuting Process " << p->getId() << "..." << endl;

                if (ReadingProcess* r = dynamic_cast<ReadingProcess*>(p)) {
                    r->loadFromFile(queue, nextId);
                    queue.dequeue();
                    delete r;
                }
                else if (PrintingProcess* pp = dynamic_cast<PrintingProcess*>(p)) {
                    pp->printProcessPool(queue);
                    queue.dequeue();
                    delete pp;
                }
                else {
                    p->execute();
                    queue.dequeue();
                    delete p;
                }
            }
            else {
                cout << "\nThe queue is empty!\n";
            }
            break;
        }
        case 3: {
            if (queue.empty()) {
                cout << "\nThe queue is empty!\n";
                break;
            }

            cout << "\nEnter Process ID to execute: ";
            int targetId;
            cin >> targetId;
            cin.ignore();

            Queue tempQueue;
            Process* target = nullptr;

            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                Process* p = queue.dequeue();
                if (p->getId() == targetId && !target) {
                    target = p;
                }
                else {
                    tempQueue.enqueue(p);
                }
            }

            while (!tempQueue.empty())
                queue.enqueue(tempQueue.dequeue());

            if (!target) {
                cout << "\nProcess with ID " << targetId << " not found!\n";
                break;
            }

            cout << "\nExecuting Process " << target->getId() << "...\n";

            if (auto* r = dynamic_cast<ReadingProcess*>(target)) {
                r->loadFromFile(queue, nextId);
            }
            else if (auto* pp = dynamic_cast<PrintingProcess*>(target)) {
                pp->printProcessPool(queue);
            }
            else {
                target->execute();
            }

            delete target;
            break;
        }
        case 4: {
            if (queue.empty()) {
                cout << "\nThe queue is empty!" << endl;
                break;
            }
            saveQueueToFile(queue, "savedQueue.txt");
            break;
        }
        case 5: {
            while (!queue.empty()) {
                delete queue.dequeue();
            }
            cout << "\n";
            loadQueueFromFile(queue, nextId, "savedQueue.txt");
            break;
        }
        }
    } while (opt != 0);
}