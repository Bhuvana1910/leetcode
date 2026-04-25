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
        int d1=INT_MIN,f1=0;
        for(int i=0;i<nums.size();i++){
           m[nums[i]]++;
           if(m[nums[i]]>f1)
           {
            d1=nums[i];
            f1=m[nums[i]];
           }
           
           if(m.find(d)!=m.end()){
            if(m[d]>=f1 && (m[d]*2)>(i+1) && ((f-m[d])*2)>(nums.size()-i-1)){
            return i;
            }
            
           }
        }
        return -1;
    }
};