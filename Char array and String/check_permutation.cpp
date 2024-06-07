#include <cstring> // Include the cstring library for strlen function

bool isPermutation(char input1[], char input2[]) {
    int countCharecters_input1[26] = {0};
    int countCharecters_input2[26] = {0};

    // Calculate character counts for input1
    for (int i = 0; input1[i] != '\0'; i++) {
        char ch = input1[i];
        if (ch >= 'a' && ch <= 'z') {
            int alpha1 = ch - 'a';
            countCharecters_input1[alpha1]++;
        }
    }

    // Calculate character counts for input2
    for (int i = 0; input2[i] != '\0'; i++) {
        char ch = input2[i];
        if (ch >= 'a' && ch <= 'z') {
            int alpha2 = ch - 'a';
            countCharecters_input2[alpha2]++;
        }
    }

    // Compare the character counts
    for (int i = 0; i < 26; i++) {
        if (countCharecters_input1[i] != countCharecters_input2[i]) {
            return false; // If counts differ for any character, they are not permutations
        }
    }

    return true; // If counts match for all characters, they are permutations
}