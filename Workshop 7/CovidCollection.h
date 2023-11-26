//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#ifndef SDDS_COVIDCOLLECTION_H
#define SDDS_COVIDCOLLECTION_H
#include <vector>
#include <list>
#include<string>

namespace sdds {
struct Covid {
    std::string m_country;
    std::string m_city;
    std::string m_variant;
    int m_year;
    size_t m_cases;
    size_t m_deaths;
    std::string m_severity = "General";
};

class CovidCollection {
    std::vector<Covid> m_collection;
public:
    CovidCollection(const std::string filename);
    void display(std::ostream& out, const std::string& country = "ALL") const;
    void sort(const std::string& field = "country");
    bool inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const;
    std::list<Covid> getListForDeaths(unsigned int deaths) const;
    void updateStatus();
};
std::ostream& operator<<(std::ostream& out, const Covid& theCovid);
}

#endif /* CovidCollection_h */
