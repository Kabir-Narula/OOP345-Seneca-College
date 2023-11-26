// Workshop 8 - Smart Pointers

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Profile.h"
#include "DataBase.h"
#include "Utilities.h"

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

bool sdds::Profile::Trace = false;

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	if (argc != 4) {
		std::cout << "\n***Incorrect number of arguments***\n";
		return cout + 1;
	}

	try {
		sdds::DataBase<sdds::Profile> allProfiles(argv[1]);
		sdds::DataBase<sdds::Profile> goodProfiles(argv[2]);
		sdds::DataBase<sdds::Profile> badProfiles(argv[3]);

		std::cout << "****************************************************" << std::endl
			<< "* All Profiles" << std::endl
			<< "****************************************************" << std::endl
			<< allProfiles << std::endl;

		std::cout << "****************************************************" << std::endl
			<< "* Good Profiles" << std::endl
			<< "****************************************************" << std::endl
			<< goodProfiles << std::endl;

		std::cout << "****************************************************" << std::endl
			<< "* Bad Profiles" << std::endl
			<< "****************************************************" << std::endl
			<< badProfiles << std::endl;

		sdds::Profile::Trace = true;
		std::cout << "****************************************************\n"
			<< "* Excluding bad profiles using Raw Pointers\n"
			<< "****************************************************\n";
		try {
			sdds::DataBase<sdds::Profile> res = sdds::excludeRaw(allProfiles, badProfiles);
		}
		catch (const std::string& msg) {
			std::cout << "ERROR: " << msg << std::endl;
			std::cout << "NOTE: An exception occurred and expected!\n";
		}

		std::cout << std::endl;
		std::cout << "****************************************************\n"
			"* Excluding bad profiles using Smart Pointers\n"
			"****************************************************\n";
		try {
			sdds::DataBase<sdds::Profile> res = sdds::excludeSmart(allProfiles, badProfiles);
		}
		catch (const std::string& msg) {
			std::cout << "ERROR: " << msg << std::endl;
			std::cout << "NOTE: An exception occurred and expected!\n";
		}

		sdds::Profile::Trace = false;
		std::cout << "\n\n";
		// no exceptions should be generated from the code below.
		std::cout << "****************************************************\n"
			"* Excluding good profiles using Raw Pointers\n"
			"****************************************************\n";
		{
			sdds::DataBase<sdds::Profile> res = sdds::excludeRaw(allProfiles, goodProfiles);
			std::cout << res << std::endl;
		}

		std::cout << "****************************************************\n"
			"* Excluding good profiles using Smart Pointers\n"
			"****************************************************\n";
		{
			sdds::DataBase<sdds::Profile> res = sdds::excludeSmart(allProfiles, goodProfiles);
			std::cout << res << std::endl;
		}
	}
	catch (...) {
		std::cout << "ERROR: Unknown error!\n";
	}
	return cout;
}
