#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        for (int i = 0; i < address.length(); i++) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
                i += 2; // Skip over the inserted "[.]" to avoid infinite loop
            }
        }
        return address;
    }
};


/*
i : from  the index.
1 : number of charecter to be replace.
"[.]"  : string to be replace.
*/