class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<queries.size();i++){
            int r1=queries[i][0],c1=queries[i][1],r2=queries[i][2],c2=queries[i][3];
            
            for(int j=r1;j<=r2;j++){
            ans[j][c1]+=1;
            if(c2+1<n){
                ans[j][c2+1]-=1;
            }
            }
        }
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
              c+=ans[i][j];
              ans[i][j]=c;
            }
        }
        return ans;
        
    }
};