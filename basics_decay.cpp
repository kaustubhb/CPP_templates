#include <iostream>
#include <type_traits>
using  namespace std;

template <typename T>
void foo1(const T param) {
  if(is_same_v<decltype(param), int>) {
    cout <<  "Same types\n";
  } else {
    cout << "different types\n";
  }
}

template <typename T>
void foo2(const T param) {
  // decay removes const-volatile qualifiers, among other things
  if(is_same_v<decay_t<decltype(param)>, int>) {
    cout <<  "Same types\n";
  } else {
    cout << "different types\n";
  }
}


int main() {
  int a = 10;
  foo1(a);
  foo2(a);
}