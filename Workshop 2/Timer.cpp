// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

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