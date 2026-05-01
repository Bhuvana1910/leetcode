class Solution {
public:
    vector<vector<vector<int>>>dp;
    int find(vector<vector<int>>&grid,int i,int j,int k){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
        return -10000;
        if (k < 0) return -10000;
        if(dp[i][j][k]!=-100000)
        return dp[i][j][k];
        if(i==grid.size()-1 && j==grid[0].size()-1){
            if(grid[i][j]==0)
            return grid[i][j];
            if(k)
            return grid[i][j];
            return -10000;
        }
        int d=grid[i][j]+find(grid,i+1,j,k-min(1,grid[i][j]));
        int r=grid[i][j]+find(grid,i,j+1,k-min(1,grid[i][j]));
        return dp[i][j][k]= max(d,r);

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        dp.assign(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k+1, -100000)));
        int ans=find(grid,0,0,k);
        return ans<0 ? -1 : ans;
    }
};