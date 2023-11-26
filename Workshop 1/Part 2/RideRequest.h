

#ifndef SDDS_RIDEREQUEST_H
#define SDDS_RIDEREQUEST_H

#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {

    class RideRequest {
        char m_customerName[11];
        char* m_rideDescription;
        double m_ridePrice;
        bool m_hasDiscount;

    public:
        RideRequest(); // previous constructor [part 1]
        ~RideRequest(); //  new destructor to deallocate memory in [part 2]
        void read(std::istream& is);
        void display() const;
        RideRequest(const RideRequest& other);
        RideRequest& operator=(const RideRequest& other);
    };
}

#endif
