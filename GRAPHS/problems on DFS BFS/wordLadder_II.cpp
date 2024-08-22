#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        vector<vector<string>> result;
        vector<string> ip = {beginWord};
        q.push(ip);
        
        bool foundEndWord = false;

        while (!q.empty() && !foundEndWord) {
            int s = q.size();
            unordered_set<string> toErase;

            for (int i = 0; i < s; i++) {
                vector<string> path = q.front();
                q.pop();
                
                string lastWord = path.back();
                
                for (int j = 0; j < lastWord.length(); j++) {
                    char originalChar = lastWord[j];
                    
                    for (char ch = 'a'; ch <= 'z'; ch++) {
                        lastWord[j] = ch;

                        if (st.find(lastWord) != st.end()) {
                            vector<string> newPath = path;
                            newPath.push_back(lastWord);

                            if (lastWord == endWord) {
                                foundEndWord = true;
                                result.push_back(newPath);
                            } else {
                                q.push(newPath);
                            }

                            toErase.insert(lastWord);
                        }
                    }
                    lastWord[j] = originalChar;
                }
            }
            //! catch point: erase word from set when that level is finished rather than that instant.
            for (const string& word : toErase) {
                st.erase(word);
            }
        }

        return result;
    }
};

signed main(int argc, char* argv[]){
    ios_base::sync_with_stdio(false);
    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        cin.tie(nullptr);
        auto _clock_start = chrono::high_resolution_clock::now();
    #endif

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    

    #ifndef YUVRAJ_SINGH_RAJPUT_DEBUG
        auto _clock_end = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(_clock_end-_clock_start).count();
        cerr << "Execution time: " << duration << " ms." << endl;
    #endif

    return 0;
}