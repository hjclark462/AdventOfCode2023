#pragma once

class Program
{
public:
	virtual void Update(float dt) = 0;
	virtual void Solve();
};