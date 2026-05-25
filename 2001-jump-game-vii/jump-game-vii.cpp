class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        vector<int>p(s.size(),0);
        p[0]=1;
        p[1]=-1;
        int t;
        for(int i=0;i<p.size();i++){
            t+=p[i];
            if(t>=1 && s[i]=='0'){
              if(i==s.size()-1)
              return true;
              if(i+minJump<s.size())
               p[i+minJump]++;
              if(i+maxJump+1<s.size())
               p[i+maxJump+1]--;  
            }
        }
        return false;
    }
};