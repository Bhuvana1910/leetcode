class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int c) {
        priority_queue<int, vector<int>, greater<int>> p, q;
        int n = costs.size();
        int i = 0;
        for (; i < c && i < n; i++)
            p.push(costs[i]);
        int j = n - 1;
        for (; j >= n - c && j >= i; j--)
            q.push(costs[j]);
        long long ans = 0;
        while (k--) {
            int left = p.empty() ? INT_MAX : p.top();
            int right = q.empty() ? INT_MAX : q.top();
            if (left <= right) {
                ans += left;
                p.pop();
                if (i <= j) {
                    p.push(costs[i]);
                    i++;
                }

            } else {
                ans += right;
                q.pop();
                if (i <= j) {
                    q.push(costs[j]);
                    j--;
                }
            }
        }
        return ans;
    }
};