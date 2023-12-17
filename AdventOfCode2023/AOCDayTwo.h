#pragma once
#include "Program.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

class AOCDayTwo : public Program
{
public:
	AOCDayTwo();
	~AOCDayTwo();

	virtual void Update(float dt);
	virtual void Solve(bool part) override;
private:
	std::fstream gameRecords;
	std::vector<std::string> files = { "input2.txt", "test.txt" };
	std::vector<std::string> colours = { "red", "green", "blue" };
	int red = 12;
	int green = 13;
	int blue = 14;
};

