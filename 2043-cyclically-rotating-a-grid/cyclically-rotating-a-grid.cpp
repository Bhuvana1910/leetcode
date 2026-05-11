class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        int v=min(n/2,m/2);
        for(int i=0;i<v;i++){
            vector<int>nums;
            int t=i,b=n-1-i,l=i,r=m-1-i;
            for(int j=l;j<=r;j++)
            nums.push_back(grid[t][j]);
            for(int j=t+1;j<=b-1;j++)
            nums.push_back(grid[j][r]);
            for(int j=r;j>=l;j--)
            nums.push_back(grid[b][j]);
            for(int j=b-1;j>=t+1;j--)
            nums.push_back(grid[j][l]);
            int k1=k%(nums.size());
            rotate(begin(nums),begin(nums)+k1,end(nums));
            int y=0;
            for(int j=l;j<=r;j++)
            grid[t][j]=nums[y++];
            for(int j=t+1;j<=b-1;j++)
            grid[j][r]=nums[y++];
            for(int j=r;j>=l;j--)
            grid[b][j]=nums[y++];
            for(int j=b-1;j>=t+1;j--)
            grid[j][l]=nums[y++];


        }
        return grid;
    }
};