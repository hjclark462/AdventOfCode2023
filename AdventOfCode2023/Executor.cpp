#include "Executor.h"
#include <time.h>

Executor::Executor(Program* program) :m_program(program)
{
	if (m_program == nullptr)
	{
		return;
	}
}

Executor::~Executor()
{
	m_running = false;
	delete m_program;
}

void Executor::Start()
{
	m_running = true;
	double fps = 1 / fixedFPS;
	time_t curTime = time(&curTime);	
	double accumulator = 0.0;

	m_program->Solve();
	while (IsRunning())
	{
		time_t newTime = time(&newTime);
		double frame = newTime - curTime;
		curTime = newTime;

		accumulator += frame;

		while (accumulator >= fixedFPS)
		{
			Update((float)fixedFPS);
			accumulator -= fixedFPS;
		}
	}
}

void Executor::Update(float dt)
{
	m_program->Update(dt);
}

bool Executor::IsRunning() const
{
	return m_running;
}