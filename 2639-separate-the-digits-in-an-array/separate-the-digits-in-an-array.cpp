class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            vector<int>temp;
            while(nums[i]){
                temp.push_back(nums[i]%10);
                nums[i]/=10;
            }
            reverse(temp.begin(),temp.end());
            for(int j=0;j<temp.size();j++)
            ans.push_back(temp[j]);
          
        }
        return ans;
    }
};