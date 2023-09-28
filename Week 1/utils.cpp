#include<iostream>
using namespace std;
using std::string;
#include "utils.h"


int* ptr = &g_data;
int g_data = 11;
static int g_secret = 777;  // static allows to redfine in main.cpp with 



void sayHello()
{
	cout << "Hi,Its Levi" << endl;
	cout << "Value of g_data: " << g_data << endl;
	cout << "Adress of G_data: " << ptr << endl;
	cout << "Value of g_secret: " << g_secret << endl;
}