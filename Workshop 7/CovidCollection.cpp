//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include "CovidCollection.h"
using namespace std;
namespace sdds {

CovidCollection::CovidCollection(const std::string filename) {
    fstream file;
    file.open(filename);
    if(file.is_open()) {
        std::string line{};
        while(getline(file, line)) {
            Covid covid;
            covid.m_country = line.substr(0, 25);
            covid.m_city = line.substr(25, 25);
            covid.m_variant = line.substr(50, 25);
            covid.m_year = std::stoi(line.substr(75, 5));
            covid.m_cases = std::stoul(line.substr(80, 5));
            covid.m_deaths = std::stoul(line.substr(85, 5));
            covid.m_country = covid.m_country.substr(covid.m_country.find_first_not_of(" "), covid.m_country.find_last_not_of(" ") + 1);
            covid.m_city = covid.m_city.substr(covid.m_city.find_first_not_of(" "), covid.m_city.find_last_not_of(" ") + 1);
            covid.m_variant = covid.m_variant.substr(covid.m_variant.find_first_not_of(" "), covid.m_variant.find_last_not_of(" ") + 1);
            covid.m_country = covid.m_country.substr(covid.m_country.find_first_not_of(" "), covid.m_country.find_last_not_of(" ") + 1);
            m_collection.push_back(covid);
        }
    }
    else {
        throw "bad file";
    }
}

void CovidCollection::display(std::ostream& out, const std::string& country) const {
    const int width = 78;

    size_t totalCases = 0, totalDeaths = 0;

    if (country == "ALL") {
        for (const auto& item : m_collection) {
            out << item << endl;
            totalCases += item.m_cases;
            totalDeaths += item.m_deaths;
        }
        out << "| " << setw(width + 1) << right << "Total cases around the world: " << totalCases << " |" << endl;
        out << "| " << setw(width + 1) << right << "Total deaths around the world: " << totalDeaths << " |" << endl;
    } else {
        out << "Displaying information of country = " + country << endl;
        for_each(m_collection.begin(), m_collection.end(), [&](Covid item){if(item.m_country == country){out << item << endl; totalCases+= item.m_cases; totalDeaths += item.m_deaths;}});
        out << "----------------------------------------------------------------------------------------" << endl;
        out << "| " << setw(78) << right << "Total cases in " + country << ": " << totalCases << " |" << endl;
        out << "| " << setw(78) << right << "Total deaths in " + country << ": " << totalDeaths << " |" << endl;
        size_t globalCases = 0, globalDeaths = 0;
        out << "| ";
        for_each(m_collection.begin(), m_collection.end(), [&](Covid item){globalCases+= item.m_cases; globalDeaths += item.m_deaths;});
        out << setw(86) << right << country + " has " + std::to_string(((double(totalCases) / double(globalCases)) * 100)) + "% of global cases and " + std::to_string(((double(totalDeaths) / double(globalDeaths)) * 100)) + "% of global deaths |" << endl;
    }
}

void CovidCollection::sort(const std::string& field) {
    std::sort(m_collection.begin(), m_collection.end(), [=](const Covid& a, const Covid& b) {
        if (field == "country") {
            if (a.m_country != b.m_country) {
                return a.m_country < b.m_country;
            }
        } else if (field == "city") {
            if (a.m_city != b.m_city) {
                return a.m_city < b.m_city;
            }
        } else if (field == "variant") {
            if (a.m_variant != b.m_variant) {
                return a.m_variant < b.m_variant;
            }
        } else if (field == "year") {
            if (a.m_year != b.m_year) {
                return a.m_year < b.m_year;
            }
        } else if (field == "cases") {
            if (a.m_cases != b.m_cases) {
                return a.m_cases < b.m_cases;
            }
        }
        return a.m_deaths < b.m_deaths;
    });
}

bool CovidCollection::inCollection(const std::string& variant, const std::string& country, unsigned int deaths) const {
    auto it = std::find_if(m_collection.begin(), m_collection.end(), [=](const Covid item) {return (country == item.m_country && variant == item.m_variant && item.m_deaths > deaths);});
    return it != m_collection.end();
}

std::list<Covid> CovidCollection::getListForDeaths(unsigned int deaths) const { 
    std::list<Covid> result;
    std::copy_if(m_collection.begin(), m_collection.end(), std::back_inserter(result), [&](const Covid &item) { return item.m_deaths >= deaths;});
    return result;
}

void CovidCollection::updateStatus() { 
    for_each(m_collection.begin(), m_collection.end(), [&](Covid &item){if(item.m_deaths > 300){item.m_severity = "EPIDEMIC";}else if(item.m_deaths < 50){item.m_severity = "EARLY";}else{item.m_severity = "MILD";}});
}


std::ostream& operator<<(std::ostream& out, const Covid& theCovid) {
    out << "| " << setw(21) << left << theCovid.m_country << " | " << setw(15) << theCovid.m_city << " | " << setw(20) << theCovid.m_variant << " | ";
    if(theCovid.m_year < 0) {
        out << "      ";
    }
    else {
        out << setw(6) << right << theCovid.m_year;
    }
    out << " | " << setw(4) << right << theCovid.m_cases << " | " << setw(3) << theCovid.m_deaths << " | | " << setw(8) << theCovid.m_severity << " |";
    return out;
}

}