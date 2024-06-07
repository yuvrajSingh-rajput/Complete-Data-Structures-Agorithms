#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for tolower() or toupper()
using namespace std;

int main() {
    string str;
    string pat;
    vector<int> result;

    cout << "Enter the input string: ";
    getline(cin, str);
    cout << "Enter the pattern to search: ";
    getline(cin, pat);

    // Convert both input string and pattern to lowercase for case-insensitive matching
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    transform(pat.begin(), pat.end(), pat.begin(), ::tolower);

    int L = 0;
    int R = pat.size() - 1;

    while (R < str.size()) {
        bool flag = true;
        for (int i = 0; i < pat.size(); i++) {
            if (pat[i] != str[L + i]) {
                flag = false;
                break; // No need to continue checking if a mismatch is found
            }
        }
        if (flag) {
            result.push_back(L);
        }
        L++;
        R++;
    }

    if (result.empty()) {
        cout << "Pattern not found in the input string." << endl;
    } else {
        cout << "Pattern found at the following indices:" << endl;
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << endl;
        }
    }

    return 0;
}
