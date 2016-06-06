#include <iostream>

using namespace std;
void printGreeting(const string name) {
  const string msg = "Hello" + name + "!";
  const int len = msg.size();
  const string stars = string(len+4, '*');
  const string edgestring = "*" + string(len+2, ' ') + "*";
  const string middlestring = "* " + msg + " *";

  cout << stars << endl
       << edgestring << endl
       << middlestring << endl
       << edgestring << endl
       << stars << endl;
}
int main() {
  cout << "Please enter your first name: ";
  // string is in the std package. std::string
  // string name means name is allocated on the stack instead of the heap
  // you can controll where you allocate objects (unlike java)
  string name;
  cin >> name;
  printGreeting(name);
  return 0;
}
