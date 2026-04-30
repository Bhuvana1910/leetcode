class Solution {
public:
    bool check(vector<int>& nums, int m, int k) {
       int count = 0;
       int left = 0;

       for (int right = 0; right < nums.size(); right++) {
         while (nums[right] - nums[left] > m) {
            left++;
         }
        count += (right - left);
        }

        return count >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int res=0;
        int l=0,h=(nums[nums.size()-1]-nums[0]);
        while(l<=h){
            int m=(l+h)/2;
            if(check(nums,m,k)){
             res=m;
             h=m-1;
            }
            else
            l=m+1;
        }
        return res;
    }
};