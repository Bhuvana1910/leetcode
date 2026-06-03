class Solution {
public:
    vector<vector<vector<int>>> dp;
    int find(vector<string>& strs,int m,int n,vector<int>&one,vector<int>&zero,int i){
        if(n<0 || m<0)
        return -10000;
        if(i==strs.size())
        return 0;
        if(dp[i][m][n]!=-1)
        return dp[i][m][n];
        int pick=1+find(strs,m-zero[i],n-one[i],one,zero,i+1);
        int notpick=find(strs,m,n,one,zero,i+1);
        return dp[i][m][n]=max(pick,notpick);

    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<int>one,zero;
        dp.resize(strs.size(), vector<vector<int>>(m+1, vector<int>(n+1, -1)));
        for(int i=0;i<strs.size();i++){
            int c0=0,c1=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0')
                c0++;
                else
                c1++;
            }
            one.push_back(c1);
            zero.push_back(c0);
        }
        return find(strs,m,n,one,zero,0);
    }
};