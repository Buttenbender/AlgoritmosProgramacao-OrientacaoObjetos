#pragma once
#include "Process.h"

template <class T>
class WritingProcess : public Process {
private:
	string expression;
public:
	WritingProcess(int id, string e);
	
	string getExpression();
	vector<string> split(const string& s, char delimiter);
	T convert(const string& str);
	bool validate();

	void execute() override;
};


// Implementing


template <class T>
WritingProcess<T>::WritingProcess(int id, string e)
	: Process(id), expression(e) {
}

template <class T>
string WritingProcess<T>::getExpression() {
	return expression;
}

template <class T>
vector<string> WritingProcess<T>::split(const string& s, char delimiter) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);

	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
}

template <class T>
T WritingProcess<T>::convert(const string& str) {
	istringstream iss(str);
	T value;
	iss >> value;

	if (iss.fail()) {
		throw runtime_error("Error converting numeric values!");
	}
	return value;
}

template <class T>
bool WritingProcess<T>::validate() {
	vector<string> parts = split(expression, ' ');

	if (parts.size() != 3) {
		return false;
	}

	string strNum1 = parts[0];
	string op = parts[1];
	string strNum2 = parts[2];

	if (op != "+" && op != "-" && op != "*" && op != "/") {
		return false;
	}

	try {
		T num1 = convert(strNum1);
		T num2 = convert(strNum2);
		(void)num1;
		(void)num2;
	}
	catch (...) {
		return false;
	}
	return true;
}

template <class T>
void WritingProcess<T>::execute() {
	try {
		if (!validate()) {
			throw runtime_error("Invalid Expression format! Expected format: 'num1 operator num2'");
		}

		ofstream archive("computation.txt", ios::app);

		if (!archive.is_open()) {
			throw runtime_error("Error opening archive computation.txt!");
		}

		archive << "[" << getId() << "] \"" << expression << "\"" << endl;
		archive.close();

		cout << "\nExpression added to the archive!" << endl;
	}
	catch (const exception& e) {
		cerr << "Error Processing Expression '" << expression << "': " << e.what() << endl;
	}
}