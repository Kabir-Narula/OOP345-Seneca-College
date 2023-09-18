
//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.
#include "RideRequest.h"

using namespace std;

double g_taxrate = 0.0;  
double g_discount = 0.0;

namespace sdds   
{
    RideRequest::RideRequest()  // constructor implementation
    {
        m_name[0] = '\0';
        m_rideDesc[0] = '\0';
        m_price = 0;
        m_discount = 0.0;
    }

    void RideRequest::read(std::istream &is)  // read function....
    {
        char discount= '\0';
        if (!is.fail()) 
        {
            is.getline(m_name, 11, ',');
            is.getline(m_rideDesc, 26, ',');
            is >> m_price;
            is.ignore(1); 

            is.get(discount);
            if (discount == 'Y')
                m_discount = true;
            else if (discount == 'N')
                m_discount = false;
        }
    }

    void RideRequest::display() const
    {

        static int counter = 1;
        cout.setf(ios::left);
        cout.width(2);
        cout << counter << ". ";
        counter++;

        cout.width(10);
        if (m_name[0] == '\0')
            cout <<"No Ride Request" << endl;
        else
        {
            cout << m_name;

            cout << "|";
            cout.width(25);
            cout << m_rideDesc;

            cout << "|";
            cout.width(12);
            cout.precision(2);
            cout << fixed << (m_price * g_taxrate) + m_price;

            cout << "|";
            if (m_discount == true)
            {
                cout.unsetf(ios::left);
                cout.setf(ios::right);
                cout.width(13);
                cout << (((m_price * g_taxrate) + m_price) - g_discount);
                cout.unsetf(ios::right);
                cout.setf(ios::left);
            }
            cout << '\n';

            cout.unsetf(ios::left);
        }
    }
}