class Solution {
public:
    int bfs(vector<vector<pair<int,int>>>& graph, int src, int dst, int k) {
        deque<pair<int,int>> q; 
        q.push_back({src, 0});
        int steps = 0;
        vector<int> cost(graph.size(), INT_MAX);
        cost[src] = 0;
        int ans = INT_MAX;
        while (!q.empty() && steps <= k) {
            int n = q.size();
            while (n--) {
                auto [node, currCost] = q.front();
                q.pop_front();
                for (auto &it : graph[node]) {
                    int next = it.first;
                    int price = it.second;
                    int newCost = currCost + price;
                    if (next == dst) {
                        ans = min(ans, newCost);
                    }
                    if (newCost < cost[next]) {
                        cost[next] = newCost;
                        q.push_back({next, newCost});
                    }
                }
            }

            steps++;
        }

        return ans;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for (auto &f : flights) {
            graph[f[0]].push_back({f[1], f[2]});
        }
        int ans = bfs(graph, src, dst, k);
        return (ans == INT_MAX) ? -1 : ans;
    }
};