// references
// serves the same purpose as pointers, with cleaner syntax
// stricter semantics
// try not to mix with points

#include <iostream>

void references() {
	using namespace std;
	int x = 10;
	int &y = x; // y is a reference to an int -- same as int* y = &x;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	y = 20;							// like *y = 20; for pointers
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	cout << "&x = " << &x << endl;
	cout << "&y = " << &y << endl; 
}

void references2() {
	using namespace std;
	int x = 10;
	const int &y = x; // you can only read x from the y reference
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
	x = 20;								// you can still write to x through the x reference
	//y = 20;		can't do this, cannot write from y
	cout << "x = " << x << endl;	
	cout << "y = " << y << endl;
	cout << "&x = " << &x << endl;
	cout << "&y = " << &y << endl; 
}
int main() {
	references2();
	return 0;
}
