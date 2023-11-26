// Workshop 8 - Smart Pointers
//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
// I did all the code by myself and only copied the code given by professor
// provided to complete my workshops and assignments.

#ifndef SDDS_PROFILE_H
#define SDDS_PROFILE_H

#include <iomanip>
#include <string>
#include <fstream>

namespace sdds
{

	const int Address_postal_code_length = 7;

	struct Address
	{
		unsigned number;
		std::string street;
		std::string postal_code;

		bool load(std::ifstream &f)
		{
			f >> number >> street;
			char postal_code_temp[1 + Address_postal_code_length + 1] = {0};
			f.read(postal_code_temp, Address_postal_code_length + 1);
			postal_code = std::string(postal_code_temp + 1);
			return f.good();
		}

		friend std::ostream &operator<<(std::ostream &os, const Address &ad)
		{
			os << std::setw(10) << ad.number << " "
				 << std::setw(10) << ad.street << " "
				 << std::setw(7) << ad.postal_code;
			return os;
		}
	};

	struct Name
	{
		std::string first_name;
		std::string last_name;
		bool load(std::ifstream &f)
		{
			f >> first_name >> last_name;
			return f.good();
		}

		friend std::ostream &operator<<(std::ostream &os, const Name &n)
		{
			os << std::setw(10) << n.first_name << std::setw(10) << n.last_name;
			return os;
		}
	};

	struct Profile
	{
		static int m_idGenerator;
		int m_id{++m_idGenerator};
		Name m_name{};
		Address m_address{};
		unsigned m_age{};
		// this variable is used to print trace messages from
		//     constructors/destructor
		static bool Trace;

		Profile() = default;

		bool load(std::ifstream &f)
		{
			m_name.load(f);
			m_address.load(f);
			f >> m_age;
			return f.good();
		}

		Profile(const Name &name, const Address &addr, unsigned age)
		{
			this->m_name = name;
			this->m_address = addr;
			this->m_age = age;
			if (Profile::Trace)
				std::cout << "     C [" << m_id << "][" << this->m_name << "]" << std::endl;
		}

		Profile(const Profile &other)
		{
			this->m_name = other.m_name;
			this->m_address = other.m_address;
			this->m_age = other.m_age;
			// we add this constructor for tracing messages
			if (Profile::Trace)
				std::cout << "    CC [" << m_id << "][" << m_name << "] copy of [" << other.m_id << "]\n";
		}

		~Profile()
		{
			if (Profile::Trace)
				std::cout << "    ~D [" << m_id << "][" << this->m_name << "]" << std::endl;
		}

		// TODO: add a function here to validate the address
		void validateAddress() const
		{
			if (m_address.number < 0 || m_address.postal_code.length() != Address_postal_code_length ||
					!std::isalpha(m_address.postal_code[0]) ||
					!std::isdigit(m_address.postal_code[1]) ||
					!std::isalpha(m_address.postal_code[2]) ||
					!std::isspace(m_address.postal_code[3]) ||
					!std::isdigit(m_address.postal_code[4]) ||
					!std::isalpha(m_address.postal_code[5]) ||
					!std::isdigit(m_address.postal_code[6]))
			{
				throw std::string("*** Invalid Address ***");
			}
		}

		friend std::ostream &operator<<(std::ostream &os, const Profile &p)
		{
			os << std::setw(5) << p.m_id
				 << std::setw(10) << p.m_name
				 << std::setw(10) << p.m_address
				 << std::setw(5) << p.m_age;
			return os << std::endl;
		}
	};

	inline int Profile::m_idGenerator{};
}
#endif
