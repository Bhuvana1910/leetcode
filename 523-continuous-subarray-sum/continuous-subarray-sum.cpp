class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int ans=0;
        m[0]=-1;
        for(int i=0;i<nums.size();i++)
        {
            ans+=nums[i];
            if(m.find(ans%k)!=m.end())
            {
                if(i-m[ans%k]>=2)
                {
                return true;
                }
            }
            else
            m[ans%k]=i;
        }
        return false;
        
    }
};