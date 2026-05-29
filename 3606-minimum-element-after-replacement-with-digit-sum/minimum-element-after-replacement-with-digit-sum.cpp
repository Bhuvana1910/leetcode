class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            string s=to_string(nums[i]);
            int val=0;
            for(int j=0;j<s.size();j++)
            {
                val+=(s[j]-'0');
                
            }
           ans=min(ans,val);
        }
        return ans;
    }
};