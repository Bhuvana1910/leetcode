class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>m;
        int d=INT_MIN,f=0;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
            if(m[nums[i]]>f){
                d=nums[i];
                f=m[nums[i]];
            }
        }
        m.clear();
        int c=0;
        for(int i=0;i<nums.size();i++){
           if(nums[i]==d)
           c++;
           if(c>0){
            if((c*2)>(i+1) && ((f-c)*2)>(nums.size()-i-1)){
            return i;
            }
            
           }
        }
        return -1;
    }
};