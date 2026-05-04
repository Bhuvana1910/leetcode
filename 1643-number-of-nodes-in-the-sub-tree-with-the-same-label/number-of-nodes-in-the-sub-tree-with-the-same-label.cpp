class Solution {
public:
    vector<int> res;
    vector<int> dfs(vector<vector<int>>& graph, string& labels, int node, int parent) {
        vector<int> freq(26, 0);
        for (int nei : graph[node]) {
            if (nei == parent) continue;
            vector<int> child = dfs(graph, labels, nei, node);
            for (int i = 0; i < 26; i++) {
                freq[i] += child[i];
            }
        }
        freq[labels[node] - 'a']++;
        res[node] = freq[labels[node] - 'a'];
        return freq;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> graph(n);
        for (auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        res.assign(n, 0);
        dfs(graph, labels, 0, -1);
        return res;
    }
};