//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
// I did all the code by myself and only copied the code given by professor
// provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include "CheeseParty.h"
using namespace std;
namespace sdds
{
    CheeseParty::CheeseParty()
    {
        m_pCheeses = nullptr;
        m_size = 0;
    }
    CheeseParty::~CheeseParty()
    {
        delete[] m_pCheeses;
    }
    CheeseParty &CheeseParty::addCheese(const Cheese &cheese)
    {
        bool flag = true;
        for (size_t i = 0; i < m_size; i++)
        {
            if (m_pCheeses[i] == &cheese)
            {
                flag = false;
            }
        }
        if (flag)
        {
            const Cheese **tmpCheeseArray = new const Cheese *[m_size + 1];
            for (size_t i = 0; i < m_size; i++)
            {
                tmpCheeseArray[i] = m_pCheeses[i];
            }
            tmpCheeseArray[m_size++] = &cheese;
            delete[] m_pCheeses;
            m_pCheeses = tmpCheeseArray;
        }
        return *this;
    }

    CheeseParty &CheeseParty::removeCheese()
    {
        for (size_t i = 0; i < m_size; i++)
        {
            if (m_pCheeses[i]->getWeight() == 0.0)
            {
                m_pCheeses[i] = nullptr;
            }
        }
        return *this;
    }
    CheeseParty::CheeseParty(const CheeseParty &source)
    {
        *this = source;
    }
    CheeseParty::CheeseParty(CheeseParty &&source)
    {
        *this = std::move(source);
    }
    CheeseParty &CheeseParty::operator=(const CheeseParty &source)
    {
        if (this != &source)
        {
            m_size = source.m_size;
            delete[] m_pCheeses;
            m_pCheeses = new const Cheese *[m_size];
            for (size_t i = 0; i < m_size; i++)
            {
                m_pCheeses[i] = source.m_pCheeses[i];
            }
        }
        return *this;
    }
    CheeseParty &CheeseParty::operator=(CheeseParty &&source)
    {
        if (this != &source)
        {
            delete[] m_pCheeses;
            m_size = source.m_size;
            m_pCheeses = source.m_pCheeses;
            source.m_pCheeses = nullptr;
        }
        return *this;
    }
    std::ostream &operator<<(std::ostream &os, CheeseParty &cheeseParty)
    {
        os << setfill('-') << setw(26) << '-' << endl;
        os << "Cheese Party" << endl;
        os << setfill('-') << setw(26) << '-' << endl;
        os << setfill(' ');
        if (cheeseParty.m_pCheeses)
        {
            for (size_t i = 0; i < cheeseParty.m_size; i++)
            {
                if (cheeseParty.m_pCheeses[i])
                {
                    os << *cheeseParty.m_pCheeses[i];
                }
            }
        }
        else
        {
            os << "This party is just getting started!" << endl;
        }
        os << setfill('-') << setw(26) << '-' << endl;
        os << setfill(' ');
        return os;
    }
}
