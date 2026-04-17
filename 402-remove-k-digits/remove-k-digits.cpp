class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>s;
        for(int i=0;i<num.size();i++){
            while(!s.empty() && num[s.top()]>num[i] && k)          {
            s.pop();
            k--; 
            }
            s.push(i);
        }
       while(k>0 && !s.empty()){
        s.pop();
        k--;
       }
       string t="";
       while(!s.empty())
       {
        t+=num[s.top()];
        s.pop();
       }
       reverse(t.begin(),t.end());
       if(t=="")
       return "0";
       int i=0;
       for(i=0;i<t.size();i++){
        if(t[i]=='0')
        continue;
        else 
        break;
       }
       if(t.substr(i)=="")
       return "0";
       return t.substr(i);
    }
};