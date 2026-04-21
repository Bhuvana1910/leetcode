class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>r,c;
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            for(int j=0;j<grid[0].size();j++){
               temp.push_back(grid[i][j]);
            }
            r[temp]++;
        }
        for(int i=0;i<grid.size();i++){
            vector<int>temp;
            for(int j=0;j<grid[0].size();j++){
               temp.push_back(grid[j][i]);
            }
            c[temp]++;
        }
        int ans=0;
        for(auto i:r){
            if(c.find(i.first)!=c.end()){
                ans+=(i.second*c[i.first]);
            }
        }
        return ans;

    }
};