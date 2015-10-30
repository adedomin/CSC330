#include <time.h>

//  Timer class to calculate time interval.
class Timer{
public:
   Timer();
   double elapsed_time();
   void reset();
private:
   clock_t start_time;
};
