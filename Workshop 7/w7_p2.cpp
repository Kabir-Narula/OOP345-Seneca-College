//==============================================
// Name           : Kabir Narula
// Email          : Knarula9@myseneca.ca
// Student ID     : 127962223
// Section        : NAA
//==============================================
//I did all the code by myself and only copied the code given by professor 
//provided to complete my workshops and assignments.

#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "CovidCollection.h"
#include "CovidCollection.h"


// Cheching if header guards exist and follow convention.
#ifndef SDDS_COVIDCOLLECTION_H
    #error "The header guard for 'CovidCollection.h' doesn't follow the convention!"
#endif

int cout = 0; // won't compile if headers don't follow convention regarding namespaces

void printbar(std::ostream& out = std::cout)
{
	out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
}

void printHeader(const char* title, std::ostream& out = std::cout)
{
	printbar(out);
	out << "| " << std::left << std::setw(85) << title << std::right << "|\n";
	printbar(out);
}

int main(int argc, char** argv)
{
	std::cout << "Command Line:\n";
	std::cout << "--------------------------\n";
	for (int i = 0; i < argc; i++)
		std::cout << std::setw(3) << i + 1 << ": " << argv[i] << '\n';
	std::cout << "--------------------------\n\n";

	sdds::CovidCollection theCollection(argv[1]);

	printHeader("The original collection");
	theCollection.display(std::cout,"ALL");
	printbar();
	theCollection.display(std::cout, "United States");
	printbar();
	theCollection.display(std::cout, "France");
	printbar();
	
	{
		printHeader("The collection sorted by country");
		theCollection.sort();
		theCollection.display(std::cout);
		printbar();
		theCollection.display(std::cout, "United States");
		printbar();
		theCollection.display(std::cout, "France");
		printbar();
		theCollection.display(std::cout, "Canada");
		printbar();
	}
	
	{
		printHeader("The collection sorted by deaths");
		theCollection.sort("DEFAULT");
		theCollection.display(std::cout, "United States");
		printbar();

		printHeader("The collection sorted by year");
		theCollection.sort("year");
		theCollection.display(std::cout, "France");
		printbar();

		printHeader("The collection sorted by variant");
		theCollection.sort("variant");
		theCollection.display(std::cout, "Canada");
		printbar();
	}
	
	{
		printHeader("More than 400 deaths");
		for (const auto& item : theCollection.getListForDeaths(400))
			std::cout << item << "\n";
	}

	{
		printHeader("More than 500 deaths");
		for (const auto& item : theCollection.getListForDeaths(500))
			std::cout << item << "\n";
	}

	printHeader("The collection with updated status");
	theCollection.updateStatus();
	theCollection.display(std::cout);
	printbar();

	{
		// looking for "Omicron" in the collection
		if (theCollection.inCollection("Omicron", "France", 300))
			std::cout << "There are cities in France with death caused by covid variants \"Omicron\" that have exccedeed 300 deaths.\n";
		else
			std::cout << "There are no cities in France with death caused by covid variants \"Omicron\" that have exccedeed 300 deaths.\n";
	}

	{
		// looking for "Omicron" in the collection
		if (theCollection.inCollection("Gamma", "United States", 200))
			std::cout << "There are cities in United States with death caused by covid variants \"Gamma\" that have exccedeed 300 deaths.\n";
		else
			std::cout << "There are no cities in United States with death caused by covid variants \"Gamma\" that have exccedeed 300 deaths.\n";
	}
	
	return cout;
}
