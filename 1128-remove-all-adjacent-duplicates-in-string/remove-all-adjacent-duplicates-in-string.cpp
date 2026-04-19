class Solution {
public:
   stack<char>st;
    string removeDuplicates(string s) {
        
        for(int i=0;i<s.size();i++)
        {
             bool f=false;
            while(!st.empty() && st.top()==s[i])
            {
                st.pop();
                f=true;
            }
            if(!f)
            st.push(s[i]);
        }
        string t;
        while(!st.empty())
        {
            t+=st.top();
            st.pop();
        }
        reverse(t.begin(),t.end());
        return t;
    }
};