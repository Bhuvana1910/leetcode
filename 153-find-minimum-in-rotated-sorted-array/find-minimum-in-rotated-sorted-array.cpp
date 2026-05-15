class Solution {
public:
    int bst(vector<int>&a){
        int l=0,h=a.size()-1,ans=INT_MAX;
        while(l<=h){
            int m=l+(h-l)/2;
            ans=min(ans,a[m]);
            if(a[m]>=a[l]){
                ans=min(ans,a[l]);
                l=m+1;
            }
            else {
               ans=min(ans,a[m]);
               h=m-1; 
            }
        }
        return ans;
    }
    int findMin(vector<int>& nums) {
        return bst(nums);
    }
};