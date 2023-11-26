
#include <iostream>
#include <iomanip>
#include "Book.h"
using namespace std;
namespace sdds
{
    Book::Book()
    {
    }
    Book::Book(const std::string &title, unsigned nChapters, unsigned nPages)
    {
        m_title = title;
        m_numChapters = nChapters;
        m_numPages = nPages;
    }

    Book::operator bool() const
    {
        bool flag = false;
        if (m_title[0] != '\0' && m_numChapters != 0 && m_numPages != 0)
        {
            flag = true;
        }
        return flag;
    }

    double Book::ratio() const
    {
        return double(m_numPages) / double(m_numChapters);
    }
    std::ostream &Book::print(std::ostream &os) const
    {
        if (*this)
        {
            if (m_numChapters < 10)
            {
                os << " ";
            }
            os << right << setw(49) << m_title << "," << right << m_numChapters << ","
               << right << m_numPages << " | " << left << setprecision(6) << fixed
               << "(" << (double)m_numPages / (double)m_numChapters << left << setw(5) << ")";
            os << fixed << defaultfloat;
        }
        else
        {
            os << "| Invalid book data";
        }
        return os;
    }

    std::ostream &operator<<(std::ostream &os, const Book &bk)
    {
        bk.print(os);
        return os;
    }

    Book &Book::operator=(const Book &rightOp)
    {
        m_title = rightOp.m_title;
        m_numPages = rightOp.m_numPages;
        m_numChapters = rightOp.m_numChapters;
        return *this;
    }
    bool Book::operator<(const Book &rightOp)
    {
        bool flag = false;
        if (ratio() < rightOp.ratio())
        {
            flag = true;
        }
        return flag;
    }

    bool Book::operator>(const Book &rightOp)
    {
        bool flag = false;
        if (ratio() > rightOp.ratio())
        {
            flag = true;
        }
        return flag;
    }
}
