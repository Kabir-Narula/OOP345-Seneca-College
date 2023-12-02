// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023


#ifndef SDDS_STATION_H
#define SDDS_STATION_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <exception>

#include <cstring>
#include <fstream>
#include <stdexcept>
#include<stddef.h>
#include <algorithm>  
#include <vector>
#include <istream>
#include <utility>
#include <iostream>
#include <sstream>
#include <iomanip>
#include "Utilities.h"
namespace sdds
{
	class Station
	{
	private: 
		int id; 
		std::string itemName;
		std::string itemDesc;
		unsigned serialNo;
		unsigned stockQty;
		static size_t m_widthField;
		static size_t id_generator;

	public:
		Station();
		Station(const std::string& str);
		const std::string& getItemName() const;
		size_t getNextSerialNumber(); 
		size_t getQuantity() const; 
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SDDS_STATION_H