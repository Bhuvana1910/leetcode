class Solution {
public:
    int mod=1000000007;
    int specialTriplets(vector<int>& nums) {
        map<int,int>m,n;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        long long c=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]--;
            if(m[nums[i]]==0)
            m.erase(nums[i]);
            if(n.find(2*nums[i])!=n.end() && m.find(2*nums[i])!=m.end())
            c=(c+(1LL*n[2*nums[i]]%mod*m[2*nums[i]]%mod))%mod;
            n[nums[i]]++;
        }
        return int(c);
    }
};