//! Returns a reference to the last character of the string.

//? This function shall not be called on empty strings.

// string::back
#include <iostream>
#include <string>

int main ()
{
  std::string str ("hello world.");
  str.back() = '!';
  std::cout << str << '\n';
  return 0;
}