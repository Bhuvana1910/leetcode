class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int>m;
        for(int i=0;i<grid.size();i++)
        {
         m[grid[i]]++;
        }
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            vector<int>temp;
            for(int j=0;j<grid[0].size();j++)
            {
                temp.push_back(grid[j][i]);
            }
            if(m.find(temp)!=m.end())
            c+=m[temp];
        }
        return c;
    }
};