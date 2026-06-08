class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>l;
        vector<int>e;
        vector<int>h;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<pivot)
            l.push_back(nums[i]);
            else if(nums[i]>pivot)
            h.push_back(nums[i]);
            else
            e.push_back(nums[i]);
        }
        l.insert(l.end(),e.begin(),e.end());
        l.insert(l.end(),h.begin(),h.end());
        return l;
    }
};