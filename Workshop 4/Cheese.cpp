//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
// I did all the code by myself and only copied the code given by professor
// provided to complete my workshops and assignments.

#include "Cheese.h"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

namespace sdds
{
    Cheese::Cheese(const std::string &str)
    {
        int i = 0;
        m_name = "";
        while (str[i] != ',')
        {
            m_name += str[i];
            i++;
        }
        m_name = removeSpaces(m_name);
        i++;
        string weight;
        while (str[i] != ',')
        {
            weight += str[i];
            i++;
        }
        m_weight = stoul(weight);
        i++;
        string price;
        while (str[i] != ',')
        {
            price += str[i];
            i++;
        }
        i++;
        m_price = stod(price);
        while (i != int(str.length()))
        {
            m_features += str[i];
            i++;
        }
        for (int i = 0; i < int(m_features.length()); i++)
        {
            if (m_features[i] == ' ')
            {
                m_features.erase(i, 1);
                --i;
            }
        }
        for (int i = 0; i < int(m_features.length()); i++)
        {
            if (m_features[i] == ',')
            {
                m_features[i] = ' ';
            }
        }
        m_features += ' ';
    }
    Cheese Cheese::slice(size_t weight)
    {
        Cheese cheese;
        if (weight <= m_weight)
        {
            cheese = *this;
            cheese.m_weight = weight;
            m_weight -= weight;
        }
        return cheese;
    }
    std::string Cheese::getName() const
    {
        return m_name;
    }
    size_t Cheese::getWeight() const
    {
        return m_weight;
    }
    double Cheese::getPrice() const
    {
        return m_price;
    }
    std::string Cheese::getFeatures() const
    {
        return m_features;
    }
    std::string removeSpaces(std::string &str)
    {
        str.erase(0, str.find_first_not_of(" "));
        str.erase(str.find_last_not_of(" ") + 1);
        return str;
    }
    std::ostream &operator<<(std::ostream &os, const Cheese cheese)
    {
        os << "|" << left << setw(21) << cheese.getName() << "|" << setw(5) << cheese.getWeight() << "|" << setw(5) << setprecision(2) << fixed << cheese.getPrice() << "|" << right << setw(34) << cheese.getFeatures() << "|" << endl;
        return os;
    }
}
