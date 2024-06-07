#include<bits/stdc++.h>
using ll = long long;
using namespace std;

class Solution {
public:
    int search(string pat, string txt) {
        unordered_map<char, int> mpp;
        for (auto &ch : pat) {
            mpp[ch]++;
        }
        int count = mpp.size();
        int pat_length = pat.length();
        int txt_length = txt.length();
        int ans = 0;

        int window_start = 0;
        int window_end = 0;

        // Initialize counts for the first window
        while (window_end < pat_length) {
            if (mpp.find(txt[window_end]) != mpp.end()) {
                mpp[txt[window_end]]--;
                if (mpp[txt[window_end]] == 0) {
                    count--;
                }
            }
            window_end++;
        }

        // Check if first window is an occurrence of the pattern
        if (count == 0) {
            ans++;
        }

        // Slide the window and check for occurrences
        while (window_end < txt_length) {
            // Remove leftmost character from the window
            if (mpp.find(txt[window_start]) != mpp.end()) {
                if (mpp[txt[window_start]] == 0) {
                    count++;
                }
                mpp[txt[window_start]]++;
            }
            window_start++;

            // Add the current character to the window
            if (mpp.find(txt[window_end]) != mpp.end()) {
                mpp[txt[window_end]]--;
                if (mpp[txt[window_end]] == 0) {
                    count--;
                }
            }
            window_end++;

            // Check if current window is an occurrence of the pattern
            if (count == 0) {
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    return 0;
}