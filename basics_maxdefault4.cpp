#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

template<typename T>
auto max(T a, T b) {
  cout <<  "Calling 0\n";
  return b < a ? a : b;
}

template<typename T1, typename T2>
auto max (T1 a, T2 b) {
  cout <<  "Calling 1\n";
  return b < a ? a : b;
}

template<typename RT, typename T1, typename T2>
RT max (T1 a, T2 b) {
  cout <<  "Calling 2\n";
  return b < a ? a : b;
}

int main() {
  // OK: only 1 is viable. Templates cannot auto deduce retrun type parameter.
  auto a = ::max(4, 7.2); 

  // OK: only 2 is viable
  auto b = ::max<long double>(7.2, 4);

  // OK: 0 and 1 are viable. But 0 is more specialized.
  // https://stackoverflow.com/questions/61332526/template-overload-resolution-with-multiple-viable-types
  auto c = ::max(1, 2);

  // ERROR: Both 1 and 2 match but what rule decides that? Later.
  auto d = ::max<int>(2, 3.0);

  // OK: 0 is the most specialized which matches.
  auto e = ::max<int>(1, 2);
}