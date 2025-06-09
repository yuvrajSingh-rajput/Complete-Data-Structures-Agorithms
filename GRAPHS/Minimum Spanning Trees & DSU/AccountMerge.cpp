class DSU {
    vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int getParent(int node) {
        if(parent[node] != node)
            parent[node] = getParent(parent[node]);
        return parent[node];
    }

    void Union(int u, int v) {
        int pu = getParent(u);
        int pv = getParent(v);
        if(pu == pv) return;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string, int> emailToAccount;

        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if(emailToAccount.find(email) == emailToAccount.end()) {
                    emailToAccount[email] = i;
                } else {
                    ds.Union(i, emailToAccount[email]);
                }
            }
        }

        vector<vector<string>> emailGroups(n);
        for(const auto& [email, accIdx] : emailToAccount) {
            int parent = ds.getParent(accIdx);
            emailGroups[parent].push_back(email);
        }

        vector<vector<string>> result;
        for(int i = 0; i < n; i++) {
            if(emailGroups[i].empty()) continue;
            sort(emailGroups[i].begin(), emailGroups[i].end());
            vector<string> merged = {accounts[i][0]};
            merged.insert(merged.end(), emailGroups[i].begin(), emailGroups[i].end());
            result.push_back(merged);
        }

        return result;
    }
};

