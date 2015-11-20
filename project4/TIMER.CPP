#include "TIMER.H"

Timer::Timer()
{
   start_time = clock();
}
 
double Timer::elapsed_time()
{
   clock_t end_time = clock();
   return ((double) (end_time - start_time)) / ((double) CLOCKS_PER_SEC);
}
 
void Timer::reset()
{
   start_time = clock();
}
