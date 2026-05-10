class Solution {
public:
    vector<int>dp;
    int find(vector<int>& nums, int target,int i){
        if(i==nums.size()-1)
        return 0;
        if(dp[i]!=-2)
        return dp[i];
        int ans=-1;
        for(int j=i+1;j<nums.size();j++){
            if(abs(nums[j]-nums[i])<=target){
            int temp=find(nums,target,j);
            if(temp!=-1)
            ans=max(ans,1+temp);
            }
        }
        return dp[i]=ans;

    }
    int maximumJumps(vector<int>& nums, int target) {
        dp.assign(nums.size(),-2);
        return find(nums,target,0);
    }
};