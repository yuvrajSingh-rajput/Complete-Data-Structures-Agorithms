#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <cstring> 
using namespace std;

//!Method 1;
void minLengthWord(char input[], char output[]) {
    int n = std::strlen(input);

    if (n == 0) {
        output[0] = '\0'; // Empty input, return an empty string
        return;
    }

    int minWordStart = 0; // Start index of the current minimum word
    int minWordLength = n; // Initialize minimum length to the length of the entire string
    int currentWordStart = 0; // Start index of the current word

    for (int i = 0; i <= n; i++) {
        if (input[i] == ' ' || input[i] == '\0') { // Found a word boundary or end of string
            int currentWordLength = i - currentWordStart;

            if (currentWordLength < minWordLength) {
                minWordLength = currentWordLength;
                minWordStart = currentWordStart;
            }

            // Move to the start of the next word
            currentWordStart = i + 1;
        }
    }

    // Copy the minimum word to the output buffer
    std::strncpy(output, input + minWordStart, minWordLength);
    output[minWordLength] = '\0'; // Null-terminate the output string
}

//!Method 2

void minLengthWord(char input[], char output[]) {
    std::vector<std::string> stringVector;
    std::vector<int> count;
    std::string word = "";

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == ' ') {
            stringVector.push_back(word);
            int l = word.length();
            count.push_back(l);
            word = "";
        }
        word.push_back(input[i]);
    }

    // Checking the minimum value index
    int min = INT_MAX, index = 0;
    for (int i = 0; i < count.size(); i++) {
        if (min > count[i]) {
            min = count[i];
            index = i;
        }
    }

    std::string shortestWord = stringVector[index];
    for (int i = 0; i < shortestWord.length(); i++) {
        output[i] = shortestWord[i];
    }
    output[shortestWord.length()] = '\0';
}
int main(){
  char ch[10000], output[10000];
  cin.getline(ch, 10000);
  minLengthWord(ch, output);
  cout << output << endl;
}
