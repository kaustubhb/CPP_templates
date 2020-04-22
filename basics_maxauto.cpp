#include <iostream>
#include <complex>
using  namespace std;

// Return type is automatically deduced from value. 
// Generally the best option
template <typename T1, typename T2>
auto max(T1 a,  T2 b) {
  return  a > b ? a : b;
}

int main() {
  cout << ::max(1, 2.3) << endl;
}