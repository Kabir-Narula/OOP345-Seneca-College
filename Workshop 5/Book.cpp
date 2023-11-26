

#include <iostream>
#include <iomanip>
#include <string>
#include "Book.h"
using namespace std;
namespace sdds {
Book::Book() {
    m_author = "";
    m_title = "";
    m_countryP = "";
    m_yearP = 0;
    m_price = 0;
    m_desc = "";
}

Book::Book(const std::string& strBook) {
    size_t i = 0;
    while(strBook[i] != ',') {
        m_author += strBook[i];
        i++;
    }
    m_author = removeSpaces(m_author);
    i++;
    while(strBook[i] != ',') {
        m_title += strBook[i];
        i++;
    }
    m_title = removeSpaces(m_title);
    i++;
    while(strBook[i] != ',') {
        m_countryP += strBook[i];
        i++;
    }
    m_countryP = removeSpaces(m_countryP);
    i++;
    std::string price;
    while(strBook[i] != ',') {
        price += strBook[i];
        i++;
    }
    i++;
    m_price = stod(price);
    std::string year;
    while(strBook[i] != ',') {
        year += strBook[i];
        i++;
    }
    i++;
    m_yearP = stoi(year);
    while(i != strBook.length()) {
        m_desc += strBook[i];
        i++;
    }
    m_desc = removeSpaces(m_desc);
}
double &Book::price() {
    return m_price;
}
const size_t &Book::year() const {
    return m_yearP;
}

const std::string &Book::country() const {
    return m_countryP;
}

const std::string &Book::title() const {
    return m_title;
}
std::ostream& operator<<(std::ostream& os, const Book& book) {
    os << setw(20) << right << book.m_author << " | "
      << setw(22) << right << book.m_title << " | "
      << setw(5) << right << book.m_countryP << " | "
      << setw(4) << right << book.m_yearP << " | "
      << setw(6) << setprecision(2) << fixed << book.m_price << " | "
      << book.m_desc << endl;
    return os;
}
std::string Book::removeSpaces(std::string& str) {
    str.erase(0, str.find_first_not_of(" "));
    str.erase(str.find_last_not_of(" ") + 1);
    return str;
}

}
