class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
      sort(nums.begin(),nums.end());
      vector<int>v(queries.size(),0);
      for(int i=0;i<queries.size();i++)
      { int ans=0;
        for(int j=0;j<nums.size();j++)
        
        {ans+=nums[j];
         if(queries[i]>=ans)
         v[i]=j+1;
        }
      } 
      return v; 
    }
};