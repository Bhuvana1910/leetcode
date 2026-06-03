class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int>v;
        unordered_map<int,int>m;
        int ans=*max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        int mi=0,r=0;
        for(int i=1;i<=ans+1;i++){
            if(m.find(i)==m.end() && mi==0 )
            mi=i;
            if(m[i]>1)
            r=i;
        }
        return {r,mi};
    }
};