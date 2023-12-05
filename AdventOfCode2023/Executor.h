#pragma once
#include "Program.h"
#include <iostream>

class Executor
{
	Program* m_program = nullptr;
public:
	Executor(Program* program);
	~Executor();

	Executor(const Executor& other) = delete;
	Executor& operator=(const Executor& other) = delete;

	void Start();
	void Update(float dt);
};

