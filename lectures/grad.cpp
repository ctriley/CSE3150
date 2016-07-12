#include <ostream>
#include <string>
#include <iostream>

class UGrad {
protected:
  std::string _name;
  double      _grade;
public:
  UGrad(const std::string& n, double g) : _name(n), _grade(g) {}
  virtual ~UGrad();
  virtual const char letterGrade() const;
  friend std::ostream& operator<<(std::ostream& os, const UGrad& ug) {
    return os << ug._name << "(UG) + " << ug._grade << '(' << ug.letterGrade() << ')' << std::endl;
  }
};

class Grad :public UGrad {
public:
  Grad(const std::string& n, double g) : UGrad(n,g) {}
  const char letterGrade() const;
  friend std::ostream& operator<<(std::ostream& os, const Grad& g) {
    return os << g._name << "(G) + " << g._grade << '(' << g.letterGrade() << std::endl;
  }
};

const char UGrad::letterGrade() const {
  if(80 < _grade && _grade <= 100)
    return 'A';
  else if (80 < _grade && _grade <= 90)
    return 'B';
  else if (70 < _grade && _grade <= 80)
    return 'C';
  else if (60 < _grade && _grade <= 70)
    return 'D';
  else return 'F';
}

const char Grad::letterGrade() const {
  if (90 < _grade && _grade <= 100) {
    return 'A';
  } else if (80 < _grade && _grade < 90) {
    return 'B';
  } else if (70 < _grade && _grade < 80) {
    return 'C';
  } else {
    return 'D';
  }
}

/*int main() {
  UGrad s1("bernard", 78);
  Grad s2("BIlly", 67);
  UGrad& gr = s2;
  std::cout << s1;
  std::cout << s2;
  std::cout << gr;
  return 0;
}

*/
