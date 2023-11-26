
#ifndef SDDS_CHEESE_H
#define SDDS_CHEESE_H
#include <iostream>
namespace sdds
{
    class Cheese
    {
        std::string m_name = "NaC";
        size_t m_weight{};
        double m_price{};
        std::string m_features{};

    public:
        Cheese() = default;
        Cheese(const std::string &str);
        Cheese slice(size_t weight);
        std::string getName() const;
        size_t getWeight() const;
        double getPrice() const;
        std::string getFeatures() const;
    };
    std::string removeSpaces(std::string &str);
    std::ostream &operator<<(std::ostream &os, const Cheese cheese);
}
#endif /* Cheese_h */
