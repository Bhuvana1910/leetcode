class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int,vector<int>>m;
        int n=mat.size();
        int mi=mat[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<mi;j++)
            {
                m[i-j].push_back(mat[i][j]);
            }
        }
        for(auto i:m){
            vector<int>temp=i.second;
            sort(temp.begin(),temp.end(),greater<int>());
            
            m[i.first]=temp;
        }
        vector<vector<int>>ans(mat.size(),vector<int>(mat[0].size()));
        for(int i=0;i<n;i++){
            for(int j=0;j<mi;j++){
                ans[i][j]=m[i-j].back();
                m[i-j].pop_back();
            }

        }
        return ans;
    }
};