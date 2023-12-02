// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023

#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include "Workstation.h"
using namespace std;
namespace sdds
{
	
	 std::deque<CustomerOrder> g_pending;
	 std::deque<CustomerOrder> g_completed;
	 std::deque<CustomerOrder> g_incomplete;

	Workstation::Workstation()
	{

	}
	Workstation::Workstation(const std::string& str) :Station(str) {}
	
	void Workstation::fill(std::ostream& os)
	{
		

		if (!m_orders.empty())
		{
			CustomerOrder* order = &(m_orders.front());
			order->fillItem(*this,os);
		}
		
	}
	//*******************************************************************************************************************************************
	bool Workstation::attemptToMoveOrder()
	{
		if (m_orders.empty())
		{
			return false;
		}
		else
		{
			
			CustomerOrder* order = &(m_orders.front());
			if (order->isItemFilled(this->getItemName()) || this->getQuantity() < 1)
			{
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(*order);
				}
				else 
				{
					
					if (order->isOrderFilled())
					{
						
						g_completed.push_back(std::move(*order));
					}
					else
					{
					
						g_incomplete.push_back(std::move(*order));
					}
				}

				m_orders.pop_front();

				return true;
			}
		}
		
		return false;

	}
	
	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}
	
	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}
	
	void Workstation::display(std::ostream& os) const
	{
		if (m_pNextStation)
		{
			os << getItemName();
			os << " --> ";
			os << m_pNextStation->getItemName();
			os << std::endl;
		}
		else
		{
			os << getItemName();
			os << " --> ";
			os << "End of Line";
			os << std::endl;
		}


	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}

}
