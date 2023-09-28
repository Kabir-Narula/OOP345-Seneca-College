void sayHello();

extern int g_data; // allows to just delcare with extern
//int g_data = 10;

extern int*  ptr;

// functions and variables have external linkage
// constant have internal linkage, so can be used only in the provided module

const int SIZE = 10; // compiler  doesnt look for SIZE in main.cpp 

class A { // its a defination // 
	// classes doesnt have memories in third stage whihc is linkage, so no issues // 
	// it can be delcared in multiple modules with same names...

	int data;

};