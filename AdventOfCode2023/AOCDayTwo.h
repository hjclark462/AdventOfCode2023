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
};

