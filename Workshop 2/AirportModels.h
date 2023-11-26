

#ifndef SDDS_AIRPORTMODELS_H
#define SDDS_AIRPORTMODELS_H

#include <iostream>
#include <string>

namespace sdds {
    struct Airport {
        std::string code{};
        std::string name{};
        std::string city{};
        std::string state{};
        std::string country{};
        double latitude{};
        double longitude{};
        friend std::ostream& operator<<(std::ostream& os, const Airport& airport);
    };

    class AirportLog {
        Airport* airports;
        size_t numAirports;

    public:
        AirportLog();
        AirportLog(const char* filename);
        AirportLog(const AirportLog& src);
        AirportLog& operator=(const AirportLog& src);
        AirportLog(AirportLog&& src);
        AirportLog& operator=(AirportLog&& src);
        ~AirportLog();

        void addAirport(const Airport& airport);
        AirportLog findAirport(const std::string& state, const std::string& country) const;
        Airport operator[](size_t index) const;
        explicit operator size_t() const;
    };
}

#endif
