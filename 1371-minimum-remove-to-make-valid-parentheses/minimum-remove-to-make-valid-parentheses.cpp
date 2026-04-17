class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st,t;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='('){
             t.push(i);
             st.push(i);
            }
            else if(s[i]==')'){
                if(!t.empty()){
                    t.pop();
                    st.push(i);
                }
            }
            else{
                st.push(i);
            }
            
        }
        string ans;
        while(!st.empty()){
            if(!t.empty() && st.top()==t.top()){
                st.pop();
                t.pop();
            }
            else{
                ans+=s[st.top()];
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};