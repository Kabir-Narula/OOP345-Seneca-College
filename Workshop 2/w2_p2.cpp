
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include "AirportModels.h"
#include "Timer.h"
#include "Timer.h"

// Cheching if header guards exist and follow convention.
#ifndef SDDS_TIMER_H
    #error "The header guard for 'Timer.h' doesn't follow the convention!"
#endif
#ifndef SDDS_AIRPORTMODELS_H
    #error "The header guard for 'AirportModels.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces




void printDivider(size_t cnt) {
    for (auto i = 0u; i < cnt; ++i)
        std::cout << "*";
    std::cout << std::endl;
}

void printHeader(const char* head) {
    std::cout << std::endl;
    printDivider(53);
    std::cout << head << std::endl;
    printDivider(53);
}

constexpr size_t MAX_OP = 7u;
struct OperationTimes
{
    // stores the times of each supported operation
    long long times[MAX_OP + 1]{}; // the last elem is invalid

    // supported operations
    const char* operations[MAX_OP]{
        "Default Constructor",
        "Custom Constructor",
        "Copy Constructor",
        "Copy Assignment Operator",
        "Move Constructor",
        "Move Assignment Operator",
        "Destructor"
    };

    long long& operator[](const char* operation)
    {
        // assuming parameter is correct
        for (auto i = 0u; i < MAX_OP; ++i)
            if (std::strcmp(operations[i], operation) == 0)
                return times[i];

        return times[MAX_OP]; // unknown operation; return the invalid elem
    }

    friend std::ostream& operator<<(std::ostream& out, const OperationTimes& ot)
    {
        out << "\n\nStatistics\n"
            "-----------------------\n";

        for (auto i = 0u; i < MAX_OP; ++i)
            out << std::setw(25) << std::right << ot.operations[i] << ": "
            << std::setw(10) << std::right << ot.times[i] << " nanoseconds.\n";

        return out;
    }
};


// ws airport_data.csv
int main(int argc, char** argv)
{
    std::cout << "Command Line:\n";
    std::cout << "--------------------------\n";
    for (int i = 0; i < argc; i++)
        std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
    std::cout << "--------------------------\n\n";

    if (argc != 2)
    {
        std::cerr << std::endl << "***Incorrect number of arguments***" << std::endl;
        return 1;
    }



    OperationTimes times;
    sdds::Timer timer;

    printHeader("Empty Airport Log entries");

    timer.start();
    sdds::AirportLog alog1;
    times["Default Constructor"] = timer.stop();

    std::cout << alog1[0] << std::endl;
    std::cout << alog1[30] << std::endl;
    std::cout << alog1[50] << std::endl;
    std::cout << alog1[size_t(alog1) - 1] << std::endl;



    printHeader("Non Empty Airport Log entries");

    timer.start();
    sdds::AirportLog alog2(argv[1]);
    times["Custom Constructor"] = timer.stop();

    std::cout << alog2[0] << std::endl;
    std::cout << alog2[30] << std::endl;
    std::cout << alog2[100] << std::endl;
    std::cout << alog2[200] << std::endl;
    std::cout << alog2[300] << std::endl;

    std::cout << alog2[size_t(alog2) - 1] << std::endl;



    printHeader("Add to Empty Airport Log");
    sdds::Airport a1{ "ADK","Adak Airport","Adak","AK","USA",51.87796,-176.64603};
    sdds::Airport a2{ "DIK","Dickinson Theodore Roosevelt Regional Airport","Dickinson","ND","USA",46.79739,-102.80195};
    sdds::Airport a3{ "IMT","Ford Airport","Iron Mountain/Kingsford","MI","USA",45.81835,-88.11454};
    sdds::Airport a4{ "TYS","McGhee Tyson Airport","Knoxville","TN","USA",35.81249,-83.99286};
    alog1.addAirport(a1);
    alog1.addAirport(a2);
    alog1.addAirport(a3);
    alog1.addAirport(a4);

    std::cout << alog1[0] << std::endl;
    std::cout << alog1[1] << std::endl;
    std::cout << alog1[2] << std::endl;
    std::cout << alog1[size_t(alog1) - 1] << std::endl;

    printHeader("Find specific state's airports");
    //std::cout << alog2.findAirport("NJ", "USA");
    sdds::AirportLog found = alog2.findAirport("AK","USA");
    std::cout << "Number of matches found: " << size_t(found) << std::endl;
    std::cout << "First match found:\n" << found[0] << std::endl;
    std::cout << "Last match found:\n" << found[size_t(found) - 1] << std::endl;

    printHeader("Find an non existing airport");
    sdds::AirportLog notfound = alog2.findAirport("Ontario","Canada");
    std::cout << "Number of airports found: " << size_t(notfound) << std::endl;




    // Part 2
    {
        printHeader("Copy Construction");


        timer.start();
        sdds::AirportLog alog = alog2;
        times["Copy Constructor"] = timer.stop();

        std::cout << alog[0] << std::endl;
        std::cout << alog[1] << std::endl;
        std::cout << alog[2] << std::endl;
        std::cout << alog[size_t(alog) - 1] << std::endl;
    }

    {
        printHeader("Copy Assignment");

        timer.start();
        alog1 = alog2;
        times["Copy Assignment Operator"] = timer.stop();
        std::cout << alog1[  0] << std::endl;
        std::cout << alog1[ 30] << std::endl;
        std::cout << alog1[100] << std::endl;
        std::cout << alog1[200] << std::endl;
        std::cout << alog1[300] << std::endl;
        std::cout << alog1[size_t(alog1) - 1] << std::endl;

        alog2 = alog2; // checking for self assignment
        alog1 = alog1;
    }

    {
        printHeader("Move Construction");

        timer.start();
        sdds::AirportLog alog = std::move(alog1);
        times["Move Constructor"] = timer.stop();

        std::cout << alog[  1] << std::endl;
        std::cout << alog[ 31] << std::endl;
        std::cout << alog[101] << std::endl;
        std::cout << alog[201] << std::endl;
        std::cout << alog[301] << std::endl;
        std::cout << alog[size_t(alog) - 1] << std::endl;

        std::cout << "First element of alog1 after move: " << alog1[0] << std::endl;
        std::cout << "Size of alog1 after move: " << size_t(alog1) << std::endl;
    }

    {
        printHeader("Move Assignment");
        sdds::AirportLog alog;

        timer.start();
        alog = std::move(alog2);
        times["Move Assignment Operator"] = timer.stop();

        std::cout << alog[  2] << std::endl;
        std::cout << alog[ 32] << std::endl;
        std::cout << alog[102] << std::endl;
        std::cout << alog[202] << std::endl;
        std::cout << alog[302] << std::endl;
        std::cout << alog[size_t(alog) - 1] << std::endl;

        std::cout << "First element of alog2 after move: " << alog2[0] << std::endl;
        std::cout << "Size of alog2 after move: " << size_t(alog2) << std::endl;

        // alog goes out of scope; record the time of the destructor
        timer.start();
    }
    times["Destructor"] = timer.stop();

    std::cout << times;

    return cout;
}
