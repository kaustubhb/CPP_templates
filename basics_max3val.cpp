#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

template<typename T>
T max(T a, T b) {
  cout <<  "Calling 1\n";
  return b < a ? a : b;
}

// max of 2 pointers
template <typename T>
T* max(T* a, T* b) {
  cout <<  "Calling 2\n";
  return *a > *b ? a : b;
}

// maximum of two C-strings:
char const* max (char const* a, char const* b) {
  cout <<  "Calling 3\n";
  return std::strcmp(b,a) < 0 ? a : b;
}

int main() {
  int a = 7, b = 42;
  auto m1 = ::max(a, b);  // 1, only 1 is viable

  string s1 = "hey", s2 = "there";
  auto m2 = ::max(s1, s2);  // 1, only 1 is viable

  int *p1 = &b, *p2 = &a;
  // 2, why? both 1 and 2 are vaible, 
  // template function with pointer types matches more closely
  auto m3 = ::max(p1, p2);   

  // const ties more closely to char*, so the underlying char* is const
  char const *x = "hello"; 
  // x[0] = 'j';   // ERROR, pointer to constant char
  char const *y = "world";
  // 3; both 2 and 3 are viable but 2 is exact match, const is also important
  auto m4 = ::max(x, y);  
}

