//! Returns a reference to the first character of the string.
// string::front
#include <iostream>
#include <string>

int main ()
{
  std::string str ("test string");
  str.front() = 'T';
  std::cout << str << '\n';
  return 0;
}