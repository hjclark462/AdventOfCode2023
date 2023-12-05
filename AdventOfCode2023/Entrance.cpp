#include "Executor.h"
int main()
{
Executor exe = Executor(new Program());

exe.Update();

return 0;
}