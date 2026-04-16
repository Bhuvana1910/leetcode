class Solution {
public:
    string removeOccurrences(string s, string part) {
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
           st.push(s[i]);
           while(st.size()>=part.size())
           {
            string t;
            for(int j=0;j<part.size();j++)  
            {
                t+=st.top();
                st.pop();
            }
            reverse(t.begin(),t.end());
            if(t!=part)
            {
                for(int k=0;k<t.size();k++)
                st.push(t[k]);
                break;
            }

           }

        }
        string g;
        while(!st.empty())
        {
            g+=st.top();
            st.pop();
        }
        reverse(g.begin(),g.end());
        return g;
            }
};