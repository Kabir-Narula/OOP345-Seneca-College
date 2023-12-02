
// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023

#define _CRT_SECURE_NO_WARNINGS
#include "Station.h"
using namespace std;
namespace sdds
{
	size_t Station::id_generator = 0;
	size_t Station::m_widthField = 0;


	Station::Station()
	{
		itemName = "";
		itemDesc="";
		serialNo=0;
		stockQty=0;
	}
	void Station::updateQuantity()
	{
		if (stockQty>0)
		{ 
			stockQty -= 1;
		}
	}

	Station::Station(const std::string& str)
	{
		id = ++id_generator;

		Utilities util; 

		size_t next_pos = 0;
		bool flag = false;
		itemName = util.extractToken(str,next_pos,flag);
		if (flag)
		{
			serialNo = std::stoi(util.extractToken(str,next_pos,flag));
		}

		if (flag)
		{
			stockQty = std::stoi(util.extractToken(str, next_pos, flag));
		}

		if (util.getFieldWidth() > Station::m_widthField)
		{
			Station::m_widthField = util.getFieldWidth();
		}

		if (flag)
		{
			itemDesc = util.extractToken(str, next_pos, flag);

		}
	}
	size_t Station::getNextSerialNumber()
	{
		return serialNo++;
	}
    const std::string& Station::getItemName() const
	{
		return itemName;
	}
	size_t Station::getQuantity() const
	{
		return stockQty;
	}
	void Station::display(std::ostream& os, bool full) const
	{
		if (!full)
		{
			os<< std::right;
			os << std::setfill('0')<<std::setw(3)<< id<< " | " <<std::setw(m_widthField)<< std::left<< std::setfill(' ')<< itemName<< " | ";
			os << std::right<< std::setfill('0')<<setw(6)<< serialNo<< " | "<< std::endl;
		}
		else
		{
			os<< std::right;
			os << std::setfill('0')<<std::setw(3)<< id<< " | ";
			os<<std::setw(m_widthField)<< std::left<< std::setfill(' ')<< itemName<< " | ";
			os << std::right<< std::setfill('0')<<setw(6)<< serialNo<< " | ";
            os<<std::setw(4)<< std::setfill(' ')<< stockQty<< " | "<< itemDesc<< std::endl;
		}
	}
}
