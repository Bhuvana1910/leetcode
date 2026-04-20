class Solution {
public:
    bool canmake(vector<int>& nums, vector<vector<int>>& queries,int m){
        vector<int>d(nums.size(),0);
        for(int i=0;i<=m;i++){
            int s=queries[i][0],e=queries[i][1],v=queries[i][2];
            d[s]-=v;
            if(e+1<nums.size())
            d[e+1]+=v;

        }
        int c=0;
        for(int i=0;i<nums.size();i++){
            c+=d[i];
            if(nums[i]+c>0)
            return false;

        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0,r=queries.size()-1,ans=-1;
        bool f=true;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
            f=false;
        }
        if(f)
        return 0;
        while(l<=r){
            int m=(l+r)/2;
            if(canmake(nums,queries,m)){
                ans=m+1;
                r=m-1;
            }
            else
            l=m+1;
        }
        return ans;
    }
};