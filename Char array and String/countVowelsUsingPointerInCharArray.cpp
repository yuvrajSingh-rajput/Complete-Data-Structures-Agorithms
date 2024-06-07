#include<iostream>
using namespace std;
void countAndPrintVowelOccurrences(char *sptr) {
    int vowelCount[5] = {0}; // Index 0 for 'a', 1 for 'e', and so on

    while ((*sptr) != '\0') {
        char ch = tolower(*sptr);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            switch (ch) {
                case 'a':
                    vowelCount[0]++;
                    break;
                case 'e':
                    vowelCount[1]++;
                    break;
                case 'i':
                    vowelCount[2]++;
                    break;
                case 'o':
                    vowelCount[3]++;
                    break;
                case 'u':
                    vowelCount[4]++;
                    break;
            }
        }
        sptr++;
    }

    cout << "Vowel 'a' occurrences: " << vowelCount[0] << endl;
    cout << "Vowel 'e' occurrences: " << vowelCount[1] << endl;
    cout << "Vowel 'i' occurrences: " << vowelCount[2] << endl;
    cout << "Vowel 'o' occurrences: " << vowelCount[3] << endl;
    cout << "Vowel 'u' occurrences: " << vowelCount[4] << endl;
}
int countVowels(char *sptr){
    int count = 0;
    while((*sptr)!='\0'){
        char ch = tolower(*sptr);
        if(ch =='a' || ch=='e' ||ch == 'i' || ch =='o'||ch=='u'){
            count++;
        }
        sptr++;
    }
    return count;
}
int main(){
    char charArray[100];
    cout<<"Enter the input string: ";
    cin.getline(charArray,100); //method to passing by getline.
    countAndPrintVowelOccurrences(charArray);
    cout<<endl;
    cout<<countVowels(charArray);
    return 0;
}