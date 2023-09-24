
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

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