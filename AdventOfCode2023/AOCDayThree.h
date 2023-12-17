#pragma once
#include "Program.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <tuple>
#include <algorithm>

class AOCDayThree :
    public Program
{
public:
	AOCDayThree();
	~AOCDayThree();

	virtual void Update(float dt);
	virtual void Solve(bool part) override;
private:
	std::fstream gameRecords;
	std::vector<std::string> files = { "input3.txt", "test.txt" };
};

