

#ifndef SDDS_CHEESESHOP_H
#define SDDS_CHEESESHOP_H
#include <iostream>
#include <iostream>
#include "Cheese.h"
namespace sdds
{
    class CheeseShop
    {
        std::string m_name{};
        const Cheese **m_pCheeses = nullptr;
        const Cheese **m_rmCheese = nullptr;
        const Cheese *m_newCheese = nullptr;
        size_t m_rmSize = 0;
        size_t m_size = 0;

    public:
        CheeseShop();
        ~CheeseShop();
        CheeseShop(const std::string &name = "No Name");
        CheeseShop &addCheese(const Cheese &cheese);
        void addCheeseRm(const Cheese &cheese);
        CheeseShop(const CheeseShop &source);
        CheeseShop(CheeseShop &&source);
        CheeseShop &operator=(const CheeseShop &source);
        CheeseShop &operator=(CheeseShop &&source);
        friend std::ostream &operator<<(std::ostream &os, CheeseShop &cheeseShop);
    };
}

#endif /* CheeseShop_h */
