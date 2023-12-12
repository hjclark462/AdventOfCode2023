#pragma once
#include "Program.h"
#include <iostream>

class Executor
{
	Program* m_program = nullptr;
protected:
	const int fixedFPS = 60;
public:
	Executor(Program* program);
	~Executor();

	Executor(const Executor& other) = delete;
	Executor& operator=(const Executor& other) = delete;

	void Start();
	void Update(float dt);

	bool IsRunning() const;
	bool m_running = false;
};

