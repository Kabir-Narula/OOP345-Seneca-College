// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <string>
#include "Movie.h"
using namespace std;
namespace sdds {
Movie::Movie() { 
    m_title = "";
    m_year = 0;
    m_desc = "";
}

const std::string &Movie::title() const { 
    return m_title;
}

Movie::Movie(const std::string &strMovie) { 
    size_t i = 0;
    while(strMovie[i] != ',') {
        m_title += strMovie[i];
        i++;
    }
    m_title = removeSpaces(m_title);
    i++;
    string year = "";
    while(strMovie[i] != ',') {
        year += strMovie[i];
        i++;
    }
    m_year = stoi(year);
    i++;
    while(i != strMovie.length()) {
        m_desc += strMovie[i];
        i++;
    }
    m_desc = removeSpaces(m_desc);
}
std::ostream& operator<<(std::ostream& os, const Movie& movie) {
    os << setw(40) << right << movie.m_title << " | "
        << setw(4) << movie.m_year << " | "
        << movie.m_desc << endl;
    return os;
}
std::string Movie::removeSpaces(std::string& str) {
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}
}
    
