

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <iostream> 
#include <chrono> 

namespace sdds
{
    class Timer
    {
        std::chrono::steady_clock::time_point timeStart; 
    public:
        void start(); 
        long long stop(); 
    }; 
}

#endif
