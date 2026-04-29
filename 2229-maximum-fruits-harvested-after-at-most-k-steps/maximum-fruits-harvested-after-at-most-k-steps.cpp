class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int Pos, int k) {
        int mp = 0;
        map<int,int> m;

      
        for (int i = 0; i < fruits.size(); i++) {
            mp = max(mp, fruits[i][0]);
            m[fruits[i][0]] = fruits[i][1];
        }

        int size = mp + k + 1;   
        vector<int> ans(size, 0);

        if (m.find(0) != m.end())
            ans[0] = m[0];

        
        for (int i = 1; i < size; i++) {
            ans[i] = ans[i-1];
            if (m.find(i) != m.end())
                ans[i] += m[i];
        }

        int res = 0;


        for (int l = 0; l <= k; l++) {
            int leftidx = max(0, Pos - l);
            int rightidx = min(size - 1, Pos + k - 2*l);

            if (leftidx > rightidx) continue;

            int val = ans[rightidx];
            if (leftidx > 0)
                val -= ans[leftidx - 1];

            res = max(res, val);
        }

        for (int r = 0; r <= k; r++) {
            int rightidx = min(size - 1, Pos + r);
            int leftidx = max(0, Pos - (k - 2*r));

            if (leftidx > rightidx) continue;

            int val = ans[rightidx];
            if (leftidx > 0)
                val -= ans[leftidx - 1];

            res = max(res, val);
        }

        return res;
    }
};