

#ifndef SDDS_LINEMANAGER_H
#define SDDS_LINEMANAGER_H

#include "Station.h"
#include "CustomerOrder.h"
#include "Workstation.h"
#include <string>
#include<deque>
#include <iostream>
namespace sdds
{
	class LineManager
	{
		std::vector<Workstation*> m_activeLine;
		size_t m_cntCustomerOrder=0;
		Workstation* m_firstStation{ nullptr };
	public:
		LineManager();
		LineManager(const std::string& file, const std::vector<Workstation*>& stations);
		void reorderStations();
		bool run(std::ostream& os);
		void display(std::ostream& os) const;

	};

}
#endif // !SDDS_LINEMANAGER_H
