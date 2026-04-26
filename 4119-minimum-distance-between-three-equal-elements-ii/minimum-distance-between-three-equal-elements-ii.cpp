class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>>m;
        for(int i=0;i<nums.size();i++)
        m[nums[i]].push_back(i);
        int ans=INT_MAX;
        for(auto i:m){
            if(i.second.size()<3)
            continue;
            vector<int>&temp=i.second;
            int s=2*(temp[2]-temp[0]),j=3;
            ans=min(ans,s);
            while(j<temp.size()){
                s=2*(temp[j]-temp[j-2]);
                ans=min(ans,s);
                j++;
            }
            

            
        }
        return ans!=INT_MAX ? ans : -1;
    }
};