class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int>s;
        for(int i=0;i<as.size();i++)
        {
            int c=as[i];
            while(!s.empty() && s.top()>0 && c<0)
            {
                if(s.top()<abs(c))
                {
                    s.pop();
                }
                else if(s.top()==abs(c)){
                s.pop();
                c=INT_MAX;
                break;
                }
                else
                {
                    c=s.top();
                    s.pop();
                }
            }
            if(c!=INT_MAX)
            s.push(c);
        }
        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
           }
};