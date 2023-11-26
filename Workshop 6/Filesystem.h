// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.


#ifndef SDDS_FILESYSTEM_H
#define SDDS_FILESYSTEM_H

#include <string>
#include "Directory.h"

namespace sdds
{
	class Filesystem
	{
		Directory* m_root{};
		Directory* m_current{};

		void addResource(std::string&, const std::string & = "");
	public:
		Filesystem(const char*, const std::string & = std::string());
		Filesystem(Filesystem&&) noexcept;
		Filesystem& operator=(Filesystem&&) noexcept;
		Filesystem& operator+=(Resource*);
		Directory* change_directory(const std::string & = "");
		Directory* get_current_directory() const;
		~Filesystem();
		Filesystem& operator=(Filesystem&) = delete;
		Filesystem(Filesystem&) = delete;
	};

	void trimString(std::string&);
}

#endif