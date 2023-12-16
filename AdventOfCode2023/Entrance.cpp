#include "Executor.h"
#include "AOCDayOne.h"

int main()
{
	Executor exe(new AOCDayOne());

	exe.Start(true);

	return 0;
}