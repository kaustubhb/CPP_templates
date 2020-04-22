#include <iostream>
#include <string>
#include <type_traits>
using namespace std;

/* The expression "true" in decltype does not matter.
 * it is the property of conditional operator to return a common type.
 * In this case, it will return double. 
 */
template <typename T1, typename T2, 
        typename RT =  decay_t<decltype(true ? T1() : T2())>>
RT max(T1 a, T2 b)  {
  return a > b  ?  a : b;
} 

int main() {
  cout << ::max(2, 2.3) << endl;
  decltype(true? int() : double()) v1 = 10.1;
  cout << v1 << endl;
}
 