class Solution {
public:
vector<int>dp;
    int find(vector<int>& arr, int d,int i){
        if(i>=arr.size())
        return INT_MIN;
        if(dp[i]!=-1)
        return dp[i];
        int rp=1;
        for(int j=1;j<=d;j++){
            if(i+j>=arr.size())
            break;
            if(arr[i]<=arr[i+j])
            break;
            rp=max(rp,1+find(arr,d,i+j));
        }
        int lp=1;
        for(int j=1;j<=d;j++){
            if(i-j<0)
            break;
            if(arr[i]<=arr[i-j])
            break;
            lp=max(lp,1+find(arr,d,i-j));
        }
        return dp[i]=max(rp,lp);

    }
    int maxJumps(vector<int>& arr, int d) {
        dp.assign(arr.size(),-1);
        int ans=INT_MIN;
        for(int i=0;i<arr.size();i++){
            ans=max(ans,find(arr,d,i));
        }
        return ans;
    }
};