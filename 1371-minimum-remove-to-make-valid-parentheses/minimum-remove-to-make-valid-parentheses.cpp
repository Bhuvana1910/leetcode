class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        stack<int>st;
        set<int>se;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(!st.empty())
                st.pop();
                else
                se.insert(i);
            }

        }
        while(!st.empty())
        {
            se.insert(st.top());
            st.pop();
        }
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(se.find(i)!=se.end())
            continue;
            else
            ans+=s[i];

        }
        return ans;
        
    
    }
};