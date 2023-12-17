#pragma once
#include "Program.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class AOCDayOne : public Program
{
public:
	AOCDayOne();
	~AOCDayOne();

	virtual void Update(float dt);
	virtual void Solve(bool part) override;

private:	
	std::vector<std::string> numStrings = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	std::vector<std::string> stringNums = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
	std::fstream calibrationValues;
	std::vector<std::string> files = { "input1.txt", "test.txt" };
};

