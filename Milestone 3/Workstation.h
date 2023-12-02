// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023

#ifndef SDDS_WORKSTATION_H
#define SDDS_WORKSTATION_H
#include "Station.h"
#include "CustomerOrder.h"
#include <string>
#include<deque>
namespace sdds
{
	extern std::deque<CustomerOrder> g_pending;
	extern std::deque<CustomerOrder> g_completed;
	extern std::deque<CustomerOrder> g_incomplete;

	class Workstation:public Station
	{
		std::deque<CustomerOrder> m_orders;
		Workstation* m_pNextStation{ nullptr };
		
	public:
		Workstation();
		Workstation(const std::string& str);
		Workstation(Workstation&) = delete;
		Workstation& operator=(Workstation&) = delete;
		Workstation(Workstation&&) = delete;
		Workstation& operator=(Workstation&&) = delete;

		void fill(std::ostream& os); 
		bool attemptToMoveOrder(); 

		void setNextStation(Workstation* = nullptr); 
		Workstation* getNextStation() const;
		void display(std::ostream& os) const;
		Workstation& operator+=(CustomerOrder&& newOrder);

	};
}
#endif // !SDDS_WORKSTATION_H
