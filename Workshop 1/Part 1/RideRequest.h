
#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H
#include <iostream>

extern double g_taxrate;  // external variable for tax rate
extern double g_discount; // external variable for discount

namespace sdds
{

    class RideRequest   // class for ride requests
    {
        // private members --------------------------------
        char m_name[11]; 
        char m_rideDesc[26];
        double m_price;
        bool m_discount;  

    public:
        RideRequest(); // default constructor
        void read(std::istream &is);  // read function accepts input stream
        void display() const;  // display function 
    };
}
#endif
