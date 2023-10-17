//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
// I did all the code by myself and only copied the code given by professor
// provided to complete my workshops and assignments.

#ifndef SDDS_CHEESEPARTY_H
#define SDDS_CHEESEPARTY_H
#include <iostream>
#include <iostream>
#include "Cheese.h"
namespace sdds
{
    class CheeseParty
    {
        const Cheese **m_pCheeses = nullptr;
        size_t m_size = 0;

    public:
        CheeseParty();
        ~CheeseParty();
        CheeseParty &addCheese(const Cheese &cheese);
        CheeseParty &removeCheese();
        CheeseParty(const CheeseParty &source);
        CheeseParty(CheeseParty &&source);
        CheeseParty &operator=(const CheeseParty &source);
        CheeseParty &operator=(CheeseParty &&source);
        friend std::ostream &operator<<(std::ostream &os, CheeseParty &cheeseParty);
    };
}

#endif /* CheeseParty_h */
