#pragma once
#include "Program.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

class AOCDayOne : public Program
{
public:
	AOCDayOne();
	~AOCDayOne();

	virtual void Update(float dt);
	virtual void Solve() override;

private:	
	std::vector<std::string> numStrings = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
};

