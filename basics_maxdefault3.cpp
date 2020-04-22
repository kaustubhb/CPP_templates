#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// common_type_t uses some template metaprogramming magic to figure out what common
// type exists to which both are implicitly convertible.
template <typename T1, typename T2, 
        typename RT = common_type_t<T1, T2>>
RT max(T1 a, T2 b)  {
  return a > b  ?  a : b;
} 

int main() {
  cout << ::max(1, 2.3) << endl;
}
