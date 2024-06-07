#include<iostream>
#include<cstring>
using namespace std;

void printSubstrings(char input[]) {
    int len = strlen(input);

    for (int start = 0; start < len; start++) {
        for (int end = start; end < len; end++) {
            for (int i = start; i <= end; i++) {
                cout << input[i];
            }
            cout << endl;
        }
    }
}