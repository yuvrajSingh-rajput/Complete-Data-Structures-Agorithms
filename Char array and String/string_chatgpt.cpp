#include <bits/stdc++.h> 

void replaceSpaces(std::string &str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ') {
            str.replace(i, 1, "@40");
            i += 3; // Move the index by 3 to account for the replacement
        }
    }
}

int main() {
    std::string input = "Hello World! This is a test.";
    replaceSpaces(input);
    std::cout << "Modified string: " << input << std::endl;
    
    return 0;
}
