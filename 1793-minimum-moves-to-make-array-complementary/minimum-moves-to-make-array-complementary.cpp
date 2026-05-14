class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>ans(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int a=nums[i],b=nums[n-i-1];
            int mv=min(a,b)+1,bv=limit+max(a,b);
            ans[2]+=2;
            ans[2*limit+1]-=2;
            ans[mv]-=1;
            ans[bv+1]+=1;
            ans[a+b]-=1;
            ans[a+b+1]+=1;
        }
        int c=ans[0]+ans[1];
        int res=INT_MAX;
        for(int i=2;i<=2*limit;i++){
          c+=ans[i];
          res=min(res,c);
        }
        return res;

    }
};