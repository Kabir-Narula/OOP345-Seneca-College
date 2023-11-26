

#include "Timer.h" 

using namespace std; 
using namespace chrono;

namespace sdds
{
    void Timer::start()
    {
        timeStart = steady_clock::now();
    }

    long long Timer::stop()
    {
        auto timeEnd = steady_clock::now(); 
        auto duration = duration_cast<nanoseconds>(timeEnd - timeStart);

        return duration.count();
    }
}
