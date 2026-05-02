class Solution {
public:
    const int NEG = -1e9;
    vector<vector<vector<int>>>dp;
    int find(vector<vector<int>>& coins,int i,int j,int k){
        if(i>=coins.size() || j>=coins[0].size())
        return -10000000;
        if(dp[i][j][k]!=NEG)
        return dp[i][j][k];
        if(i==coins.size()-1 && j==coins[0].size()-1)
        {
            if(coins[i][j]<0 && k)
            return 0;
            return coins[i][j];
        }
        int r=-10000000,r1=-10000000,l=-10000000,l1=-10000000;
        if(coins[i][j]<0 && k){
            r1=find(coins,i,j+1,k-1);
        }
        r=coins[i][j]+find(coins,i,j+1,k);
        r=max(r,r1);
        if(coins[i][j]<0 && k){
            l1=find(coins,i+1,j,k-1);
        }
        l=coins[i][j]+find(coins,i+1,j,k);
        l=max(l,l1);
        return dp[i][j][k]=max(r,l);




    }
    int maximumAmount(vector<vector<int>>& coins) {
        dp.assign(coins.size(),vector<vector<int>>(coins[0].size(),vector<int>(3,NEG)));
        return find (coins,0,0,2);
    }
};