#include "Executor.h"
#include "AOCDayFour.h"

int main()
{
	Executor exe(new AOCDayFour());

	exe.Start(true);

	return 0;
}