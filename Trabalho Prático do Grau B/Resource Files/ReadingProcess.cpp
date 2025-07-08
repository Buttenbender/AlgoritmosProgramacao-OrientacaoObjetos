#include "ReadingProcess.h"

ReadingProcess::ReadingProcess(int id)
	: Process(id) { }

void ReadingProcess::loadFromFile(Queue& queue, int& nextId) {
	ifstream file("computation.txt");
	if (!file.is_open()) {
		cerr << "Error: Unable to open computation.txt!\n";
		return;
	}

	string line;
	while (getline(file, line)) {
		size_t bracketClose = line.find("]");
		if (bracketClose == string::npos) {
			continue;
		}

		string rest = line.substr(bracketClose + 1);
		rest.erase(remove(rest.begin(), rest.end(), '"'), rest.end());
		rest.erase(0, rest.find_first_not_of(" \t"));

		Process* p = nullptr;

		auto tryCreate = [&](auto typeTag) -> Process* {
			using T = decltype(typeTag);
			auto* temp = new ComputingProcess<T>(nextId, rest);
			if (temp->validate()) {
				return temp;
			}
			delete temp;
			return nullptr;
		};

		if ((p = tryCreate(double{}))) {
			queue.enqueue(p);
			cout << "\nLoaded Expression '" << rest << "' as double process " << nextId++ << "\n";
		}
		else if ((p = tryCreate(float{}))) {
			queue.enqueue(p);
			cout << "\nLoaded Expression '" << rest << "' as float process " << nextId++ << "\n";
		}
		else if ((p = tryCreate(int{}))) {
			queue.enqueue(p);
			cout << "\nLoaded Expression '" << rest << "' as int process " << nextId++ << "\n";
		}
		else {
			cerr << "\nFailed to validate Expressions!" << endl;
		}
	}
	file.close();

	ofstream clearFile("computation.txt", ios::trunc);
	clearFile.close();

	cout << "\nReading Process finished loading Expressions!" << endl;
}

void ReadingProcess::execute() {
	cout << "\nReading Process " << getId() << " is ready to load Expressions from file!" << endl;
}