class Solution {
public:
    string processStr(string s) {
         string ans;
          for(int i=0;i<s.size();i++){
           if(s[i]=='#'){
           if(ans.size()>0)
           ans+=ans;
           }
           else if(s[i]=='%')
           reverse(ans.begin(),ans.end());
           else if(s[i]=='*'){
           if(ans.size()>0)
           ans.erase(ans.size()-1,1);
           }
           else
           ans+=s[i];
          }
          return ans;
    }
};