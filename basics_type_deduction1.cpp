#include <iostream>
#include <string>
using namespace std;

template <typename T>
void foo(T t = "") {
  cout << "foo: " << t << endl;
}

template <typename T = string>
void bar(T t = "") {
  cout << "bar: " << t << endl;
}

int main() {
  foo("abc"); // OK
  foo(1);     // OK

  // ERROR; type deduction does not work for default arguments.
  // foo();

  foo<string>();  // OK

  // ERROR: provided type int does not match default argument ""
  // foo<int>();

  bar();      // OK, default argument for template type parameter specified.
}