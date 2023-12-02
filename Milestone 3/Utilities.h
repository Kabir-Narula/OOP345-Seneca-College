


// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023

#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <istream>
#include <cstring>
#include <iomanip>
#include <utility>
#include <fstream>
#include<stddef.h>
#include <exception>
#include <stdexcept>
#include <algorithm> 

namespace sdds
{
	class Utilities
	{
	private:
		size_t m_widthField=1; 
		static char m_delimiter;
		void Trim_Space(std::string& word); 

	public:
		Utilities();
		void setFieldWidth(size_t newWidth);
		size_t getFieldWidth() const;
		std::string extractToken(const std::string& str, size_t& next_pos, bool& more); 								static void setDelimiter(char newDelimiter);
		static char getDelimiter(); 

	};
}
#endif // !SDDS_UTILITIES_H