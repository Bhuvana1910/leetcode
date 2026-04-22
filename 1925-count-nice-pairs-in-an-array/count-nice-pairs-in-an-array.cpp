class Solution {
public:
    int mo=1000000007;
    int countNicePairs(vector<int>& nums) {
        map<int,int>m;
        for(int i=0;i<nums.size();i++){
            string t=to_string(nums[i]);
            reverse(t.begin(),t.end());
            m[stoi(t)-nums[i]]++;
        }
        int ans=0;
        for(auto i:m){
            long long x = i.second;
            ans = (ans + (x * (x - 1) / 2) % mo) % mo;

        }
        return ans;
    }
};