class Solution {
public:
bool checkor(vector<bool>&v)
{
    bool f=v[v.size()-1];
    for(int i=v.size()-2;i>=0;i--)
    { 
        f|=v[i];

    }
    return f;

}
bool checkand(vector<bool>&v)
{
    bool f=true;
    for(int i=v.size()-1;i>=0;i--)
    { 
        f&=v[i];

    }
    return f;

}
    bool parseBoolExpr(string expression) {
        if(expression.size()==1){
            if(expression[0]=='f')
            return false;
            return true; 
        }
        stack<char>st;
        
        for(int i=0;i<expression.size();i++)
        {
            if(expression[i]==',')
            continue;
            else if(expression[i]==')')
            {
              vector<bool>v;
              while(!st.empty())
              {
                if(st.top()=='(')
                {
                    st.pop();
                    break;
                }
                else
                {
                    if(st.top()=='t')
                    v.push_back(true);
                    else
                    v.push_back(false);
                    st.pop();
                }
                
              }
              char ex=st.top();
                st.pop();
                bool ans;
                if(ex=='!')
                {
                    if(v[0]==true)
                    ans=false;
                    else
                    ans=true;
                }
                else if(ex=='|')
                {
                    ans=checkor(v);
                }
                else{
                    ans=checkand(v);
                }
                if(ans==true){
                    if(st.empty())
                    return ans;
                    else
                    st.push('t');
                }
                else{
                   if(st.empty())
                    return ans;
                    else
                    st.push('f'); 
                }
            }
            else
            st.push(expression[i]);
        }
        return true;
    }
};