//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
// I did all the code by myself and only copied the code given by the professor
// provided to complete my workshops and assignments.

#ifndef SDDS_DATABASE_H
#define SDDS_DATABASE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>
#include <stdexcept> // Added for std::runtime_error

namespace sdds
{
    template <typename T>
    class DataBase
    {
        std::vector<T> database;

    public:
        DataBase() {}
        DataBase(const char *filename) // Changed fn to filename for consistency
        {
            std::ifstream file(filename);
            if (!file)
            {
                throw std::runtime_error("Failed to open file: " + std::string(filename));
            }

            while (file)
            {
                T e;
                try
                {
                    if (e.load(file))
                        database.push_back(T(e));
                }
                catch (...)
                {
                    break;
                }
            }

            file.close(); // Close the file explicitly
        }

        size_t size() const { return database.size(); }
        const T &operator[](size_t i) const { return database[i]; }

        // Private helper function to avoid code duplication
        template <typename U>
        void addItem(U newItem)
        {
            database.push_back(*newItem);
        }

        // Overload the += operator with a raw pointer as a second operand.
        DataBase<T> &operator+=(T *newItem)
        {
            addItem(newItem);
            return *this;
        }

        // Overload the += operator with a smart pointer as a second operand.
        DataBase<T> &operator+=(std::shared_ptr<T> newItem)
        {
            addItem(newItem);
            return *this;
        }

        void display(std::ostream &os) const
        {
            os << std::fixed << std::setprecision(2);
            for (auto &e : database)
                os << e;
        }
    };

    template <typename T>
    std::ostream &operator<<(std::ostream &os, const DataBase<T> &db)
    {
        db.display(os);
        return os;
    }
}

#endif
