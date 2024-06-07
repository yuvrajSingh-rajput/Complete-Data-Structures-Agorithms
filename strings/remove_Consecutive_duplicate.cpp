#include<iostream>
using namespace std;

string removeConsecutiveDuplicates(string str) {
  // Write your code here
  int start = 0;
  for (int i = start + 1; i < str.length(); i++) {
    if (str[start] == str[i]) {
      str.erase(i, 1);
      i--;
    } else {
      start = start + 1;
    }
  }
  return str;
}