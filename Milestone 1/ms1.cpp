// Name: Kabir Narula
// Seneca Student ID: 127962223
// Seneca email: knarula9@myseneca.ca
// Date of completion: 11 November 2023
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

// Final Project
// Milestone 1
// ms1_prof.cpp
// Winter 2021
// Chris Szalwinski

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Station.h"
#include "Station.h"
#include "Utilities.h"
#include "Utilities.h"

using namespace std;
using namespace sdds;

static bool loadStations(const char *, vector<Station> &);

int main(int argc, char **argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl
			 << endl;
	if (argc < 3)
	{
		cerr << "ERROR: Insufficient number of arguments\n";
		return 1;
	}

	//**************//
	vector<Station> theStations;
	try
	{
		Utilities::setDelimiter(',');
		loadStations(argv[1], theStations);
		Utilities::setDelimiter('|');
		loadStations(argv[2], theStations);
	}
	catch (const string &err)
	{
		cerr << err << '\n';
		exit(2);
	}

	cout << "========================================" << endl;
	cout << "=         Stations (summary)           =" << endl;
	cout << "========================================" << endl;
	for (Station &theItem : theStations)
		theItem.display(cout, false);
	cout << endl
			 << endl;

	cout << "========================================" << endl;
	cout << "=          Stations (full)             =" << endl;
	cout << "========================================" << endl;
	for (Station &theItem : theStations)
		theItem.display(cout, true);
	cout << endl
			 << endl;

	// Select an object and verify all the functionality it working
	cout << "========================================" << endl;
	cout << "=          Manual Validation           =" << endl;
	cout << "========================================" << endl;
	cout << "getItemName(): " << theStations[0].getItemName() << endl;
	cout << "getNextSerialNumber(): " << theStations[0].getNextSerialNumber() << endl;
	cout << "getNextSerialNumber(): " << theStations[0].getNextSerialNumber() << endl;
	cout << "getQuantity(): " << theStations[0].getQuantity() << endl;
	theStations[0].updateQuantity();
	cout << "getQuantity(): " << theStations[0].getQuantity() << endl;
	cout << endl;

	cout << "========================================" << endl;
	cout << "=              Utilities               =" << endl;
	cout << "========================================" << endl;
	// create & initialize an array of input data
	const struct
	{
		char delim;
		std::string data;
	} input[]{
			{'a', "a"},
			{'b', "a"},
			{'l', "Hello"},
			{',', "apple,orange,banana,kiwi,strawberry,yellow watermellon"},
			{'|', "Gengar|Arcanine|Bulbasaur|Blaziken|C h a r i z a r d|Umbreon|Lucario|Eevee"}};

	for (auto &item : input)
	{
		Utilities::setDelimiter(item.delim);
		Utilities util;
		bool more = true; // if there are more tokens in the input string
		size_t pos = 0u;	// position of the next token in the input string
		cout << "Data: [" << item.data << "]    Delimiter: [" << item.delim << "]\n";
		while (more)
		{
			try
			{
				auto token = util.extractToken(item.data, pos, more);
				cout << "   Token: [" << token << "] [" << util.getFieldWidth() << "]\n";
			}
			catch (...)
			{
				cout << "   ERROR: No token.\n";
			}
		}
	}

	return 0;
}

bool loadStations(const char *filenameSt, vector<Station> &theStations)
{
	std::ifstream file(filenameSt);
	if (!file)
		throw string("Unable to open [") + filenameSt + "] file";

	// each line from the file represents an item;
	// read one at a time and add it to the inventory
	string theRecord;
	while (!file.eof())
	{
		std::getline(file, theRecord);
		Station newItem(theRecord);
		theStations.push_back(std::move(newItem));
	}
	file.close();
	return true;
}
