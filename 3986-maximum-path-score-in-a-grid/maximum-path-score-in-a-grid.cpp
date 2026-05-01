class Solution {
public:
    vector<vector<vector<int>>>dp;
    int maxPathScore(vector<vector<int>>& grid, int k) {
        dp.assign(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k+1, -100000)));
        int n=grid.size(),m=grid[0].size();
        for(int l=0;l<=k;l++){
            if(grid[n-1][m-1]==0)
            dp[n-1][m-1][l]=0;
            else if(l)
            dp[n-1][m-1][l]=grid[n-1][m-1];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                for(int l=0;l<=k;l++){
                    int d=-100000,r=-100000;
                    if(i==n-1 && j==m-1)
                    continue;
                    int cost = (grid[i][j] == 0 ? 0 : 1);
                    if (l < cost) continue;
                    if(i+1<n)
                    d=grid[i][j]+dp[i+1][j][l-cost];
                    if(j+1<m)
                    r=grid[i][j]+dp[i][j+1][l-cost];
                    dp[i][j][l]=max(d,r);

                }
            }
        }
        return dp[0][0][k]>=0?dp[0][0][k]:-1;
        
    }
};