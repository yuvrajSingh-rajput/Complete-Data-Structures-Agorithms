class Solution {
    vector<int> bfs(vector<vector<int>> &adj, int node, vector<bool>& vis){
        queue<int> q;
        q.push(node);
        vis[node] = true;
        vector<int> ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);

            for(auto adjNode: adj[u]){
                if(!vis[adjNode]){
                    q.push(adjNode);
                    vis[adjNode] = true;
                }
            }
        }

        return ans;
    }
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<vector<int>> adj(n);
        vector<set<string>> emails;

        // push the emails in to a set to optimize the search
        for(int i = 0; i < n; i++){
            set<string> st;
            for(int j = 1; j < accounts[i].size(); j++) st.insert(accounts[i][j]);
            emails.push_back(st);
        }

        // created a graph
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                for(auto it: emails[j]){
                    if(emails[i].find(it) != emails[i].end()){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                        break;
                    }
                }
            }
        }

        // find the connected components
        vector<bool> vis(n, false);
        vector<vector<int>> res;
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                vector<int> conn = bfs(adj, i, vis);
                res.push_back(conn);
            }
        }
        vector<vector<string>> ans;
        for(int i = 0; i < res.size(); i++){
            set<string> st;
            for(auto idx: res[i]){
                for(auto it: emails[idx]){
                    st.insert(it);
                }
            }
            vector<string> temp = {accounts[res[i][0]][0]};
            for(auto it: st) temp.push_back(it);

            ans.push_back(temp);
        }

        return ans;
    }
};
