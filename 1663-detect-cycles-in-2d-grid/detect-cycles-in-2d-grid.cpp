class Solution {
public:
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj, vector<vector<int>>& vis){
        vis[i][j] = 1;
        
        for(auto &d : dir){
            int ni = i + d[0];
            int nj = j + d[1];
            
            if(ni>=0 && nj>=0 && ni<grid.size() && nj<grid[0].size() && grid[ni][nj] == grid[i][j]){
                if(!vis[ni][nj]){
                    if(dfs(grid, ni, nj, i, j, vis))
                        return true;
                }
                else if(ni != pi || nj != pj){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!vis[i][j]){
                    if(dfs(grid, i, j, -1, -1, vis))
                        return true;
                }
            }
        }
        
        return false;
    }
};