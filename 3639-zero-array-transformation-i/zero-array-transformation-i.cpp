class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans(nums.size(),0);
        
    for(int i=0;i<queries.size();i++)
    {
        int f=queries[i][0];
        int l=queries[i][1];
        ans[f]-=1;
        if(l+1<nums.size())
        ans[l+1]+=1;

    }
    int c=0; 
    if(nums[0]+ans[0]<=0)
    c++;  
    for(int j=1;j<nums.size();j++)
    {
        ans[j]=ans[j]+ans[j-1];
        if(nums[j]+ans[j]<=0)
        {
            c++;
        }

    }
    if(c==nums.size())
    return true;
    else
    return false;

    }

};
