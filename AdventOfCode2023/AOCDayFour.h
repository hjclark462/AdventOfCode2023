#pragma once
#include "Program.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <tuple>
#include <algorithm>

class AOCDayFour : public Program
{
public:
	AOCDayFour();
	~AOCDayFour();

	virtual void Update(float dt);
	virtual void Solve(bool part) override;
private:
	std::fstream scratchCards;
	std::vector<std::string> files = { "input4.txt", "test.txt" };
};

