#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// Finds the common type between T1 and T2, that is, the type which both
// T1 and T2 can implicitly be converted to.
template <typename T1, typename T2>
common_type_t<T1,  T2> max(T1 a, T2 b)  {
  return a > b  ?  a : b;
} 

int main() {
  cout << ::max(1, 2.3) << endl;
}