


#include <iostream>
#include <fstream>
#include <string>
#include "AirportModels.h"

using namespace std;

namespace sdds {
    ostream& operator<<(ostream& os, const Airport& airport) {
        char oldfill = os.fill();
        os.fill('.');
        if (!airport.code.empty()) {
            os.setf(ios::right);
            os.width(20);
            os << "Airport Code";
            os << " : ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os.width(30);
            os << airport.code << endl;

            os.unsetf(ios::left);
            os.setf(ios::right);
            os.width(20);
            os << "Airport Name";
            os << " : ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os.width(30);
            os << airport.name << endl;

            os.unsetf(ios::left);
            os.setf(ios::right);
            os.width(20);
            os << "City";
            os << " : ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os.width(30);
            os << airport.city << endl;

            os.unsetf(ios::left);
            os.setf(ios::right);
            os.width(20);
            os << "State";
            os << " : ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os.width(30);
            os << airport.state << endl;

            os.unsetf(ios::left);
            os.setf(ios::right);
            os.width(20);
            os << "Country";
            os << " : ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os.width(30);
            os << airport.country << endl;

            os.unsetf(ios::left);
            os.setf(ios::right);
            os.width(20);
            os << "Latitude";
            os << " : ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os.width(30);
            os << airport.latitude << endl;

            os.unsetf(ios::left);
            os.setf(ios::right);
            os.width(20);
            os << "Longitude";
            os << " : ";
            os.unsetf(ios::right);
            os.setf(ios::left);
            os.width(30);
            os << airport.longitude << "\n";

            os.fill(oldfill);
            os.unsetf(ios::left);
        } else
            os << "Empty Airport";
        return os;
    }

    AirportLog::AirportLog() : airports(nullptr), numAirports(0) {}

    AirportLog::AirportLog(const char* filename) {
        int numRecords = 0;
        char newline = '\0';
        string ignoreLine = "";
        ifstream file(filename);

        if (file.is_open()) {
            while (file.get(newline)) {
                if (newline == '\n')
                    numRecords++;
            }
        }
        numAirports = numRecords - 1;
        airports = new Airport[numAirports];

        file.clear();
        file.seekg(0, ios::beg);
        getline(file, ignoreLine);

        for (size_t i = 0; i < numAirports; i++) {
            getline(file, airports[i].code, ',');
            getline(file, airports[i].name, ',');
            getline(file, airports[i].city, ',');
            getline(file, airports[i].state, ',');
            getline(file, airports[i].country, ',');
            file >> airports[i].latitude;
            file.ignore(1, ',');
            file >> airports[i].longitude;
            file.ignore(1, '\n');
        }
    }

    AirportLog::AirportLog(const AirportLog& src) {
        airports = nullptr;
        *this = src;
    }

    AirportLog& AirportLog::operator=(const AirportLog& src) {
        if (this != &src) {
            delete[] airports;

            numAirports = src.numAirports;

            if (src.airports != nullptr) {
                airports = new Airport[numAirports];

                for (size_t i = 0; i < numAirports; i++) {
                    airports[i].code = src.airports[i].code;
                    airports[i].name = src.airports[i].name;
                    airports[i].city = src.airports[i].city;
                    airports[i].state = src.airports[i].state;
                    airports[i].country = src.airports[i].country;
                    airports[i].latitude = src.airports[i].latitude;
                    airports[i].longitude = src.airports[i].longitude;
                }
            } else
                airports = nullptr;
        }
        return *this;
    }

    AirportLog::~AirportLog() {
        delete[] airports;
        airports = nullptr;
    }

    AirportLog::AirportLog(AirportLog&& src) {
        airports = nullptr;
        *this = std::move(src);
    }

    AirportLog& AirportLog::operator=(AirportLog&& src) {
        if (this != &src) {
            delete[] airports;

            numAirports = src.numAirports;
            src.numAirports = 0;

            airports = src.airports;
            src.airports = nullptr;
        }

        return *this;
    }

    void AirportLog::addAirport(const Airport& airport) {
        numAirports++;
        Airport* tmp = new Airport[numAirports];

        for (size_t i = 0; i < numAirports - 1; i++) {
            tmp[i] = airports[i];
        }

        tmp[numAirports - 1] = airport;
        delete[] airports;
        airports = tmp;
    }

    AirportLog AirportLog::findAirport(const std::string& state, const std::string& country) const {
        AirportLog foundAirports;
        for (size_t i = 0; i < numAirports; i++) {
            if (airports[i].state == state && airports[i].country == country) {
                foundAirports.addAirport(airports[i]);
            }
        }
        return foundAirports;
    }

    Airport AirportLog::operator[](size_t index) const {
        if (index < numAirports)
            return airports[index];
        else {
            Airport emptyAirport;
            return emptyAirport;
        }
    }

    AirportLog::operator size_t() const {
        return numAirports;
    }
}
