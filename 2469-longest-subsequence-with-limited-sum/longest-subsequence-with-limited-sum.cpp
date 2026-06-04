class Solution {
public:
int check(int l,int h,vector<int> &v,int i,vector<int>& queries)
{int ans=0;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(queries[i]>=v[mid])
        {
        l=mid+1;
        ans=mid+1;
        }
        else 
        h=mid-1;
    }
    return ans;
}

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        vector<int>v(nums.size());
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
           sum+=nums[i];
           v[i]=sum;
        }
        vector<int>a(queries.size(),0);
        int l=0;
        int h=v.size()-1;
        for(int i=0;i<queries.size();i++)
        {
        int c=check(l,h,v,i,queries);
        a[i]=c;
        }
        return a;
    }
};