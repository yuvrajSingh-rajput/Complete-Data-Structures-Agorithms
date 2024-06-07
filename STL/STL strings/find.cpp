#include <iostream>
#include <string>
 
int main()
{
    std::string s = "A,B,C,";
    std::string substr = ",";
 
    int index = 0;
    while ((index = s.find(substr, index)) != std::string::npos) {
        std::cout << index << std::endl;
        index += substr.length();
    }
 
    return 0;
}