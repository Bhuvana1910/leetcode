class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[i-nums[i]]++;
        }
        long long ans=0,pf=0;
        for(auto i:m){
            long long f=i.second*1LL;
            long long f1=nums.size()-f-pf;
            ans+=(f*f1);
            pf+=f;
        }
        return ans;
    }
};