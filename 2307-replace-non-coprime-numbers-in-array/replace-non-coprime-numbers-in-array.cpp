class Solution {
public:
    int gcd(int a,int b){
        if(b<=0)
        return a;
        if(a<=0)
        return b;
        return gcd(b,a%b);
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
      stack<int>s;
      vector<int>ans;
      for(int i=0;i<nums.size();i++){
        long long c=nums[i];
        while(!s.empty() && gcd(s.top(),c)>1){
         c=(1LL*s.top()*c)/gcd(s.top(),c);
         s.pop();
        }
        s.push(c);
      }  
      while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};