class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        set<int>s;
        for(int i=0;i<target.size();i++){
            s.insert(target[i]);
        }
        vector<string>ans;
        for(int i=1;i<=n;i++){
            if(s.find(i)!=s.end()){
             ans.push_back("Push");
             s.erase(i);
            }
            else{
             if(!s.empty()){
             ans.push_back("Push");
             ans.push_back("Pop");
             }
            }
        }
        return ans;
    }
};