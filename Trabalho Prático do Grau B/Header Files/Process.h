#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <fstream>
#include <regex>
#include <typeinfo>
#include <iomanip>
using namespace std;

class Process {
private:
	int id;
public:
	Process(int id);
	int getId() const;
	virtual void execute() = 0;
};