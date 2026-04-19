class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0,ans=0;
        while(i<nums1.size()){
         while(j<nums2.size() && nums1[i]<=nums2[j])
         j++;

         if(j-i>=0)
         ans=max(ans,(j-1)-i);
         i++;
        }
        return ans;

    }
};