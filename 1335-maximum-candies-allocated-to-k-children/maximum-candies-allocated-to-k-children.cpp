class Solution {
public:
bool check(vector<int>& candies,int m, long long k)
{
    for(int i=0;i<candies.size();i++)
    {
        if(candies[i]>=m)
        k-=(candies[i]/m);
    }
    if(k>0)
    return false;
    return true;

}
    int maximumCandies(vector<int>& candies, long long k) {
        int l=1,h=*max_element(candies.begin(),candies.end());
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(check(candies,mid,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
        }
        return ans;

    }
};