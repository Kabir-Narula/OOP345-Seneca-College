//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <iostream>
namespace sdds {
class Book
{
    std::string m_title{};
    unsigned m_numChapters{};
    unsigned m_numPages{};
public:
    Book();
    Book(const std::string& title, unsigned nChapters, unsigned nPages);
    
    // TODO: In completing Part 1, add here the missing
    // member prototypes that would be necessary for the
    // Collection module code and tester module w3_p1.cpp
    // to manage Book-type objects.
    //
    // In completing Part 2, add here the missing
    // member prototypes that would be necessary for
    // OrderedCollection module code and tester module
    // w3_p2.cpp to manage Book-type object.
    //
    // Write the implementations of these functions
    // in Book.cpp file
    double ratio() const;
    std::ostream& print(std::ostream& os) const;
    operator bool() const;
    Book& operator=(const Book& rightOp);
    bool operator<(const Book& rightOp);
    bool operator>(const Book& rightOp);
};
std::ostream& operator<<(std::ostream& os, const Book& bk);
}


#endif /* Book_h */
