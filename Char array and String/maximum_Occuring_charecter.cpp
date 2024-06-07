#include<iostream>
using namespace std;

//! Most optimized;
char highestOccurringChar(char input[]) {
    int countCharecter[26] = {0};
    char mostFrequentChar = '\0'; // Initialize with a null character
    int maxCount = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];
        if (ch >= 'a' && ch <= 'z') { // Check if the character is a lowercase letter
            int alpha = ch - 'a';
            countCharecter[alpha]++;
            
            // Check if the current character has a higher count
            if (countCharecter[alpha] > maxCount) {
                maxCount = countCharecter[alpha];
                mostFrequentChar = ch;
            }
            else if (countCharecter[alpha] == maxCount && ch < mostFrequentChar) {
                // If counts are equal, select the lexicographically smaller character
                mostFrequentChar = ch;
            }
        }
    }

    return mostFrequentChar;
}


//! Method 2;
char maximum_occuring_char(string s){
    int arr[26] = {0};
    for(int i=0;i<s.size();i++){
        int alpha = 0;
        char ch  = s[i];
            alpha = ch - 'a'; //gives the index of required alphatical charecter position for lowercase. 
        arr[alpha]++;
    }

    // calculating maximum of array.
    int max = -1,ans;
    for(int i=0;i<26;i++){
        if(arr[i]>max){
            ans = i;
            max = arr[i];
        }
    }
    char chr = ans + 97;
    return chr;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    getline(cin,s);
    cout<<maximum_occuring_char(s);
    return 0;
}