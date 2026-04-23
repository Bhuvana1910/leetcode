class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
       vector<long long>ans(nums.size(),0);
       map<int,long long>m,n;
       vector<long long>l(nums.size(),0),lf(nums.size(),0);
       for(int i=0;i<nums.size();i++){
       if(m.find(nums[i])!=m.end())
       l[i]=m[nums[i]];
       if(n.find(nums[i])!=n.end())
       lf[i]=n[nums[i]];
       m[nums[i]]+=(1LL*i);
       n[nums[i]]++;
       }
       cout<<m[1]<<endl;
       for(int i=0;i<nums.size();i++){
        long long t=m[nums[i]];
        long long ls=l[i];
        long long rs=t-ls-i;
        long long le=lf[i];
        long long re=n[nums[i]]-lf[i]-1;
        long long res=0;
        res+=(i*le);
        if(i==2)
        cout<<res<<" ";
        res-=ls;
        if(i==2)
        cout<<res<<" ";
        res+=rs;
        if(i==2)
        cout<<res<<" ";
        res-=(re*i);
        if(i==2)
        cout<<res<<" ";
        ans[i]=res;
        if(i==2){
            cout<<t<<" "<<ls<<" "<<rs<<" "<<le<<" "<<re<<" ";
        }
       }
       return ans;
       
    }
};