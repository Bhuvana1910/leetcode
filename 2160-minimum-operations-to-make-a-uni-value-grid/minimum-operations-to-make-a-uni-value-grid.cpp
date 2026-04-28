class Solution {
public:
    int find(vector<int>&v,int x,int k){
    int c=0;
    for(int i=0;i<v.size();i++){
        if(abs(k-v[i])%x==0){
            c+=abs(k-v[i])/x;
        }
        else
        return INT_MAX;
    }
    return c;
    }
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int>v;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            v.push_back(grid[i][j]);
        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        if(v.size()%2==0)
        {
        int idx=(v.size()/2);
        ans=min(ans,find(v,x,v[idx]));
        ans=min(ans,find(v,x,v[idx-1]));
        }
        else
        ans=min(ans,find(v,x,v[v.size()/2]));
        return ans!=INT_MAX?ans:-1;
    }
};