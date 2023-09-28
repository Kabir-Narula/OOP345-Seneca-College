#include <iostream>
#include <string>
using namespace std;
using std::string;
#include "utils.h"




extern int g_secret; // can be redecalred with same name cox of static keyword in utils.cpp...

// USE OF CONSTEXPR------------------------------------------------

constexpr int getsize(int seed) { // the result of the function can be known at compile time for for at least som parameters...

	return 2 * seed;

}


int main(int argc, char** argv) {

	// USE OF ARGC AND ARGV------------------------------------------------

	/*cout << "Received [" << argc << "] Parameters"<< endl;
	for (int i = 1; i < argc; ++i) // loop to count the number of parameters
	cout << argv[i] << endl; // prints the  number of parameters */

	/*volatile const  int a  = 12; // volatile allows not to optimize the value of a variable

	int* constMaybe = const_cast<int*>(&a); // const_cast<int*> allows to accept paramater as constant
	*constMaybe = 45;

	cout << "False Value: " << a << " " <<  (int*)&a  << endl; // they have same address
	cout << "True Value: " << *constMaybe << " " <<  constMaybe << endl;  /// they have same address */

	// CONST VS CONSTEXPR--------------------------------

	/* int size = -1;
	cout << "Size? ";
	cin >> size;

	const int SIZE  = size; // constant should always be initialized , cannot change value...
	constexpr int CE_SIZE = 10; // a constant + value must be null at compile time

	//int arr[CE_SIZE]; //size must be constant and not changed, should be known at compile time

	int arr[getsize(10)];*/

	//EXTERNAL VS INTERNAL LINKAGE--------------------------------


	//hello();

	g_secret = 32;
	sayHello(); 
	

	cout << g_secret << endl;
	//g_data = 567; cannot redeclare


	return 0;
}

