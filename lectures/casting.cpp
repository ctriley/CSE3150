#include <iostream>

int staticc() {
	int x = 10;
	char c = 'a';
	//int* p = static_cast<int*>(&c);  // creates an error
	return 0;
}

int constc() {
	using namespace std;
	const int x = 10;
	int* p = const_cast<int*>(&x);		// this is stripping away the const from the pointer
	*p = 20;
	cout << "p = " << p << endl;
	cout << "&x = " << &x << endl;
	cout << "x = " << x << endl;
	cout << "*p = " << *p << endl;
	return 0; 
}

void reinterpert() {
	// behaves like c, no checks.
	// if you want c like behavior it is better to use this than the c method
	// this is very dangerous
}

void dynamicc() {
	// convert between types in the same heirachy
	// makes sure cast makes sense at run time, returns null if it makes no sense.
	
}

int main() {
	constc();
	return 0;
}