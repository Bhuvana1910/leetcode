class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
      
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='[')
            st.push('[');
            else if(s[i]==']'){
            if(!st.empty() && st.top()=='[')
              st.pop();
            }

        }
        if(st.empty())
        return 0;
        int n=st.size();
        int ans=(n+1)/2;
        return ans;

    }
};