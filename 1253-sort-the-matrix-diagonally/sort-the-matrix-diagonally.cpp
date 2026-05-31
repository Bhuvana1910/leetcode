class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>u;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                u[i-j].push_back(mat[i][j]);
            }
        }
        for(auto i:u)
        {
          vector<int>temp=i.second;
          sort(temp.begin(),temp.end(),greater<int>());
          u[i.first]=temp;

        }
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                ans[i][j]=u[i-j].back();
                u[i-j].pop_back();
            }
        }
        return ans;
    }
};