class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int s=accumulate(nums.begin(),nums.end(),0),ans=INT_MIN,n=nums.size();
       int prev=0;
       for(int i=0;i<nums.size();i++)
       prev+=(i*nums[i]);
       ans=max(ans,prev);
       for(int i=1;i<nums.size();i++){
        int c=prev+s-(n*nums[n-i]);
        ans=max(ans,c);
        prev=c;
       } 
       return ans;
    }
};