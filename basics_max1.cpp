#include <iostream>
#include <complex>
using  namespace std;

// template <typename T>
// T max(T& a, T& b) {
//   cout << "Calling 1\n";
//   return a > b ? a : b;
// }

template <typename T>
T max(const T& a, const T& b) {
  cout << "Calling 2\n"; 
  return a > b ? a : b;
}

template <typename T>
void foo(T*) {
  cout << "Calling 3\n"; 
  // do nothing
}

int main() {
  std::string s1 = "abc", s2 = "def";
  // 1, why is non const chosen? template overload resolution does not know
  // anything about how max is using the arguments. It may be changing them.
  // Since s1 and s2 are not const, they match more closely. If 1 is commentd out, 
  // 2 ill still match.
  cout << ::max(s1, s2) << endl;  

  const std::string s3 = "abc", s4 = "def";
  cout << ::max(s3, s4) << endl;  // 2

  cout << ::max(2, 4) << endl;    // 2

  // complex<int> c1, c2;
  // ::max(c1, c2);   // ERROR; ordering not defined for complex numbers
  
  void *p = nullptr;
  foo(p);     // 3
}