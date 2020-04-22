#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

// maximum of two int values:
int max (int a, int b) {
  cout << "Called 1\n";
  return b < a ? a : b;
}

// maximum of two values of any type:
template<typename T>
T max (T a, T b) {
  cout << "Called 2\n";
  return b < a ? a : b;
}

/* If the template can generate a function with a better match, 
 * however, then the template is selected.
 */
int main() {
  ::max(7, 42);           // 1, non template exact match.
  ::max(7.0, 42.0);       // 2 better match after template deduction.
  ::max('a', 'b');        // 2
  ::max<>(7, 42);         // 2, as template deduction is requested explicitly.
  ::max<double>(7, 42);   // 2
  ::max('a', 42.7);       // 1, as automatic type conversion is not considered for 
                          // deduced template parameters                          
}