class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>p(nums.size(),0);
        vector<int>s(nums.size(),0);
        vector<int>ans(nums.size(),0);
        int sum=0;
        for(int i=1;i<nums.size();i++)
        {
            sum+=nums[i-1];
            p[i]=sum;
        }
        sum=0;
        for(int i=nums.size()-2;i>=0;i--)
        {
            sum+=nums[i+1];
            s[i]=sum;
        }
        for(int i=0;i<nums.size();i++)
        {
            ans[i]=abs(s[i]-p[i]);
        }
        return ans;
    }
};