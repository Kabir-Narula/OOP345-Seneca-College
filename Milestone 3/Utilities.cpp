// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023
#define _CRT_SECURE_NO_WARNINGS
 
#include "Utilities.h"
using namespace std;
namespace sdds
{
	char Utilities::m_delimiter ='\0';

	Utilities::Utilities()
	{	

	}

	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	
    void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		std::string word;
		size_t deli_Pos = str.find_first_of(m_delimiter, next_pos);
		
		if (next_pos == std::string::npos && more)
		{
			more = false;
			throw "exception occured";
		}
		
		if (str.at(next_pos) == m_delimiter && more)
		{
		
			more = false;
			throw "if a delimiter is found at next_pos";

		}
		
		if (deli_Pos == std::string::npos)
		{
			word = str.substr(next_pos);
			Trim_Space(word);
			next_pos = std::string::npos;
			more = false;
		}
		else
		{	word = str.substr(next_pos, deli_Pos-next_pos);
			Trim_Space(word);
			next_pos = deli_Pos + 1;
			more = true;
			
		}

		if (m_widthField<word.length())
		{
			m_widthField = word.length();
		}
		return word;
	
	}

	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}

    void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}

	void Utilities::Trim_Space(std::string& word)
	{

		while (word.find(" ") == 0)
		{
			word.erase(0, 1);
		}

		word.erase(std::find_if(word.rbegin(), word.rend(), [](unsigned char ch) {
			return !std::isspace(ch);
			}).base(), word.end());

	}

}
