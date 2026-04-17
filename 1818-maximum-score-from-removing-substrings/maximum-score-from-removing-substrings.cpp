class Solution {
public:
    int find(string &s, int x, string b){
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.size();i++){
            st.push(s[i]);
            while(!st.empty() && st.size()>=2 ){
              string t;
              for(int j=0;j<2;j++){
                t+=st.top();
                st.pop();
              }
              reverse(t.begin(),t.end());
              if(b==t)
              ans+=x;
              else{
                for(int j=0;j<2;j++)
                {
                    st.push(t[j]);
                }
                break;
              }
            }
        }
        s.clear();
        while(!st.empty()){
            s+=(st.top());
            st.pop();
        }
        reverse(s.begin(),s.end());
        return ans;
    }
    int maximumGain(string s, int x, int y) {
        string a,b;
        int ans = 0;

        if(x >= y){
           ans += find(s, x, "ab");
           ans += find(s, y, "ba");
        }
        else{
           ans += find(s, y, "ba");  
           ans += find(s, x, "ab");
        }
        return ans;
    }
};