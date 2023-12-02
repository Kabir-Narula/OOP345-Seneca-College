
// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <string>
#include <iomanip>
#include <algorithm>
#include <istream>
#include "CustomerOrder.h"
#include "Utilities.h"
using namespace std;
namespace sdds
{
	size_t CustomerOrder::m_widthField = 0;

	CustomerOrder::CustomerOrder()
	{
		m_name = "";
		m_product = "";
	}

	CustomerOrder::CustomerOrder(const std::string& str)
	{
		Utilities util; 
		size_t next_pos = 0;
		bool more = false;
		int i = 0;
		delete[] m_lstItem;
		m_name = util.extractToken(str, next_pos, more);
		if (more)
		{
			m_product = util.extractToken(str, next_pos, more);
		}
		std::string remain = "";
		if (more)
		{
			remain = str.substr(next_pos);
		}
		size_t count_delim = std::count(remain.begin(), remain.end(), util.getDelimiter());
		count_delim += 1; 
		m_cntItem = count_delim;
		m_lstItem = new Item * [m_cntItem];

		next_pos = 0;
		while (more)
		{
			std::string item_name = util.extractToken(remain, next_pos, more);
			Item* item = new Item(item_name);
			m_lstItem[i] = item;
			i++;
	
		}
		if (util.getFieldWidth() > CustomerOrder::m_widthField)
		{
			CustomerOrder::m_widthField = util.getFieldWidth();
		}

	}

	bool CustomerOrder::isOrderFilled() const
	{
		bool flag = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled != true)
			{
				flag = false;
				break;
			}
		}
		return flag;

	}

	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		bool flag = true;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled == false)
			{
				flag = false;
			}		
		}
		return flag;
	}

	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			Item* currentItem = m_lstItem[i]; 
			if (station.getItemName() == currentItem->m_itemName && !currentItem->m_isFilled)
			{
				if (station.getQuantity() > 0)
				{
					station.updateQuantity();
					currentItem->m_serialNumber = station.getNextSerialNumber();
					currentItem->m_isFilled = true;
					os << "    Filled " << m_name << ", " << m_product << " [" << currentItem->m_itemName << "]" << endl;
					break;
				}
				else
				{
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << currentItem->m_itemName << "]" << endl;
				}
			}
	
		}
	}
    
	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name;
		os << " - " << m_product  << std::endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << std::right;
			os << "[" << std::setfill('0')<<std::setw(6) << m_lstItem[i]->m_serialNumber << "] ";
			os << std::left << setfill(' ');
			os << setw(CustomerOrder::m_widthField);
			os << m_lstItem[i]->m_itemName << " - ";
			if (m_lstItem[i]->m_isFilled == true)
			{
				os << "FILLED" << std::endl;
			}
			else
			{
				os << "TO BE FILLED" << std::endl;

			}
		}
	}

	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& copy)noexcept
	{
		if (this != &copy)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;
			m_lstItem = nullptr;

			m_name = copy.m_name;
			m_product = copy.m_product;
			m_cntItem = copy.m_cntItem;
			m_lstItem = copy.m_lstItem;

			copy.m_name = "";
			copy.m_product = "";
			copy.m_cntItem = 0;
			copy.m_lstItem = nullptr;
		}
		return *this;
	}

    CustomerOrder::CustomerOrder(CustomerOrder&& copy)noexcept
	{
		if (this != &copy)
		{
			*this = std::move(copy);
		}
	}

	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
		m_lstItem=nullptr;
	}

	CustomerOrder::CustomerOrder(CustomerOrder& copy)
	{
		throw "An Exception has occured";
	}
}
