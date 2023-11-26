

#include "RideRequest.h"
#include <cstring>
#include <iomanip>

using namespace std;
double g_taxrate = 0.0;
double g_discount = 0.0;

namespace sdds
{

    // Constructor:
    RideRequest::RideRequest()
    {
        m_customerName[0] = '\0';
        m_rideDescription = nullptr;
        m_ridePrice = 0.0;
        m_hasDiscount = false;
    }

    // Copy Constructor:
RideRequest::RideRequest(const RideRequest &other)
{
    strcpy(m_customerName, other.m_customerName);

    if (other.m_rideDescription != nullptr) {
        m_rideDescription = new char[strlen(other.m_rideDescription) + 1];
        strcpy(m_rideDescription, other.m_rideDescription);
    } else {
        m_rideDescription = nullptr;
    }

    m_ridePrice = other.m_ridePrice;

    m_hasDiscount = other.m_hasDiscount;
}

    // Copy Assignment Operator:
   RideRequest &RideRequest::operator=(const RideRequest &other)
{
    if (this != &other)
    { 
        delete[] m_rideDescription;

        strcpy(m_customerName, other.m_customerName);

        if (other.m_rideDescription != nullptr) {
            m_rideDescription = new char[strlen(other.m_rideDescription) + 1];
            strcpy(m_rideDescription, other.m_rideDescription);
        } else {
            m_rideDescription = nullptr;
        }

        m_ridePrice = other.m_ridePrice;

        m_hasDiscount = other.m_hasDiscount;
    }
    return *this;
}


    // Destructor:
    RideRequest::~RideRequest()
    {
        delete[] m_rideDescription;
    }

    // Read function:
   void RideRequest::read(istream &is)
{
    char discountStatus = '\0';

    // Deallocate any existing memory for m_rideDescription
    delete[] m_rideDescription;

    if (!is.fail())
    {
        is.getline(m_customerName, 11, ',');

        char tempDescription[256];
        is.getline(tempDescription, sizeof(tempDescription), ',');

        m_rideDescription = new char[strlen(tempDescription) + 1];
        strcpy(m_rideDescription, tempDescription);

        is >> m_ridePrice;
        is.ignore(1); // Ignore the comma

        is.get(discountStatus);
        if (discountStatus == 'Y')
            m_hasDiscount = true;
        else if (discountStatus == 'N')
            m_hasDiscount = false;
    }
    is.ignore(1);
}


    // Display function:
    void RideRequest::display() const
    {
        static int requestCounter = 1;
        cout.setf(ios::left);
        cout.width(2);
        cout << requestCounter << ". ";
        requestCounter++;

        cout.width(10);
        if (m_customerName[0] == '\0')
            cout << "No Ride Request" << endl;
        else
        {
            cout << m_customerName;

            cout << "|";
            cout.width(25);
            cout << m_rideDescription;

            cout << "|";
            cout.width(12);
            cout.precision(2);
            cout << fixed << (m_ridePrice * g_taxrate) + m_ridePrice;

            cout << "|";
            if (m_hasDiscount == true)
            {
                cout.unsetf(ios::left);
                cout.setf(ios::right);
                cout.width(13);
                cout << (((m_ridePrice * g_taxrate) + m_ridePrice) - g_discount);
                cout.unsetf(ios::right);
                cout.setf(ios::left);
            }
            cout << '\n';

            cout.unsetf(ios::left);
        }
    }
}
