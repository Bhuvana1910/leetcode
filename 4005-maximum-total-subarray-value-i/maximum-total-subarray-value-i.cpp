class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans=0;
         long long mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<nums.size();i++){
              mi=min(mi,nums[i]*1LL);
              ma=max(ma,nums[i]*1LL);
              ans=max(ans,ma-mi);
        }
        return ans*k;

    }
};