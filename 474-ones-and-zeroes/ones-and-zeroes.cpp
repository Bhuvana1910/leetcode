class Solution {
public:
    vector<vector<vector<int>>> dp;
    int find(vector<string>& strs,int m,int n,vector<int>&one,vector<int>&zero,int i){
        if(n<0 || m<0)
        return -10000;
        if(i==strs.size())
        return 0;
        if(dp[i][m][n]!=-1)
        return dp[i][m][n];
        int pick=1+find(strs,m-zero[i],n-one[i],one,zero,i+1);
        int notpick=find(strs,m,n,one,zero,i+1);
        return dp[i][m][n]=max(pick,notpick);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int  l=strs.size();
        dp.resize(l + 1,
                  vector<vector<int>>(m + 1,
                  vector<int>(n + 1, 0)));

        vector<int> one, zero;

        for (int i = 0; i < l; i++) {
            int c0 = 0, c1 = 0;

            for (char ch : strs[i]) {
                if (ch == '0')
                    c0++;
                else
                    c1++;
            }

            zero.push_back(c0);
            one.push_back(c1);
        }

        for (int i = l - 1; i >= 0; i--) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {

                 
                    dp[i][j][k] = dp[i + 1][j][k];

                   
                    if (j >= zero[i] && k >= one[i]) {
                        dp[i][j][k] = max(
                            dp[i][j][k],
                            1 + dp[i + 1][j - zero[i]][k - one[i]]
                        );
                    }
                }
            }
        }

        return dp[0][m][n];
        
    }
};