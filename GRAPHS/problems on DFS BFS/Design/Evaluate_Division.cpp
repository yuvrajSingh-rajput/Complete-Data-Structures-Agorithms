class Solution {
public:
    bool dfs(const string& u, const string& v, unordered_map<string, unordered_map<string, double>>& graph, unordered_set<string>& visited, double& result) {
        if (u == v) {
            return true;
        }

        visited.insert(u);

        for (const auto& neighbor : graph[u]) {
            if (visited.find(neighbor.first) == visited.end()) {
                result *= neighbor.second;
                if (dfs(neighbor.first, v, graph, visited, result)) {
                    return true;
                }
                result /= neighbor.second;
            }
        }

        return false;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0], v = equations[i][1];
            graph[u][v] = values[i];
            graph[v][u] = 1.0 / values[i];
        }

        vector<double> result;
        for (const auto& query : queries) {
            string u = query[0], v = query[1];

            if (graph.find(u) == graph.end() || graph.find(v) == graph.end()) {
                result.push_back(-1.0);
                continue;
            }

            if (u == v) {
                result.push_back(1.0);
                continue;
            }

            unordered_set<string> visited;
            double pathResult = 1.0;

            if (dfs(u, v, graph, visited, pathResult)) {
                result.push_back(pathResult);
            } else {
                result.push_back(-1.0);
            }
        }

        return result;
    }
};
