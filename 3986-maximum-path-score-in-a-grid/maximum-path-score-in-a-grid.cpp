class Solution {
public:
    vector<vector<vector<int>>> dp;
    int find(vector<vector<int>>& grid,int i,int j, int k){
        if(k<0)
        return -10000;
        if(i==grid.size()-1 && j==grid[i].size()-1){
        if(grid[i][j]==0)
        return grid[i][j];
        if(k>=1)
        return grid[i][j];
        return -10000;
        }
        
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[i].size()-1)
        return -10000;
        if(dp[i][j][k]!=-1)
        return dp[i][j][k];
        int right=grid[i][j]+find(grid,i,j+1,k-min(1,grid[i][j]));
        int down=grid[i][j]+find(grid,i+1,j,k-min(1,grid[i][j]));
       return dp[i][j][k]=max(right,down);

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
     dp.assign(grid.size(), vector<vector<int>>(grid[0].size(), vector<int>(k+1, -1)));
     int ans=find(grid,0,0,k);
     if(ans<0)
     return -1;
     return ans;
    }
};