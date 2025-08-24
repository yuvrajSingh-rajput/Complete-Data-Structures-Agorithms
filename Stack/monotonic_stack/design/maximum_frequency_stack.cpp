class FreqStack {
    unordered_map<int, int> count;             
    unordered_map<int, vector<int>> group;     
    int maxFreq;
public:
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        int f = ++count[val];
        if(f > maxFreq) maxFreq = f;
        group[f].push_back(val);
    }
    
    int pop() {
        int val = group[maxFreq].back();
        group[maxFreq].pop_back();
        count[val]--;
        if(group[maxFreq].empty()) maxFreq--;
        return val;
    }
};
