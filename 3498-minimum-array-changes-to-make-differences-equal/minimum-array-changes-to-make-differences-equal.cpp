class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        vector<int>ans(k+2,0);
        int n=nums.size();
        for(int i=0;i<n/2;i++){
            int a=nums[i],b=nums[n-i-1];
            int mv=0;
            int bv = max({a, b, k-a, k-b});
            ans[0]+=2;
            ans[k+1]-=2;
            ans[mv]-=1;
            ans[bv+1]+=1;
            ans[abs(b-a)]-=1;
            ans[abs(b-a)+1]+=1;
        }
        int cur = 0;
        int res = INT_MAX;
        for(int i = 0; i <= k; i++){
            cur += ans[i];
            res = min(res, cur);
        }
        return res;
    }
};