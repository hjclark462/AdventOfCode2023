#include "Executor.h"
#include "AOCDayThree.h"

int main()
{
	Executor exe(new AOCDayThree());

	exe.Start(true);

	return 0;
}