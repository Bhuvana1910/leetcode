class Solution {
public:
    bool isGood(vector<int>& nums) {
        int v=*max_element(nums.begin(),nums.end());
        if(nums.size()!=v+1)
        return false;
        map<int,int>m;
        for(int i=0;i<nums.size();i++)
        m[nums[i]]++;
        for(int i=1;i<=v;i++){
            if(m.find(i)==m.end())
            return false;
            if(m[v]!=2)
            return false;
        }
        return true;
        
    }
};