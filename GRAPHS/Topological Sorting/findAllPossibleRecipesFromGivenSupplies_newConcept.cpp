class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string, vector<string>> graph;
        unordered_set<string> st(supplies.begin(), supplies.end());

        unordered_map<string, int> indegree;
        indegree.clear();

        for(auto recipe : recipes) indegree[recipe] = 0;

        for(int i = 0;i<recipes.size();i++){
            for(int j = 0;j<ingredients[i].size();j++){
                if(st.find(ingredients[i][j]) == st.end()){
                    graph[ingredients[i][j]].push_back(recipes[i]);
                    indegree[recipes[i]]++;
                }
            }
        }

        vector<string> ans;
        queue<string> q;

        for(auto it : indegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }

        while(!q.empty()){
            // cout << "done" << endl;
            auto recipe = q.front();
            q.pop();

            ans.push_back(recipe);

            for(auto it : graph[recipe]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        return ans;
    }
};
