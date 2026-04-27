class Solution {
public:
    map<int, vector<vector<int>>> m = {
    {1, {{0,-1},{0,1}}},
    {2, {{-1,0},{1,0}}},
    {3, {{0,-1},{1,0}}},
    {4, {{0,1},{1,0}}},
    {5, {{0,-1},{-1,0}}},
    {6, {{-1,0},{0,1}}}
};
    bool find(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis){
        if(i==grid.size()-1 && j==grid[0].size()-1)
        return true;
        vis[i][j]=1;
        for(auto &d:m[grid[i][j]]){
            int new_i=i+d[0];
            int new_j=j+d[1];
            if(new_i<0 || new_j<0 || new_i>=grid.size() || new_j>=grid[0].size() || vis[new_i][new_j]==1)
            continue;
        for(auto &nd:m[grid[new_i][new_j]]){
            if(new_i+nd[0]==i && new_j+nd[1]==j && find(grid,new_i,new_j,vis))
            return true;
        }
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        return find(grid,0,0,vis);
    }
};