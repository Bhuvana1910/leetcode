class Solution {
public:
bool checks(vector<int>& nums)
{
    for(int i=0;i<nums.size()-1;i++)
    {
        if(nums[i]>nums[i+1])
        return false;
    }
    return true;
}
    bool check(vector<int>& nums) {
        if(checks(nums))
        return true;
        for(int i=0;i<nums.size();i++)
        {
          int temp=nums[nums.size()-1];
          for(int j=nums.size()-2;j>=0;j--){
            nums[j+1]=nums[j];
          }
          nums[0]=temp;
          if(checks(nums))
          return true;
          
        }
        return false;
    }
};