class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        for(int i=0;i<nums1.size();i++)
        s.insert(nums1[i]);
        for(int i=0;i<nums2.size();i++){
            if(s.find(nums2[i])!=s.end())
            return nums2[i];
        }
        return -1;
    }
};