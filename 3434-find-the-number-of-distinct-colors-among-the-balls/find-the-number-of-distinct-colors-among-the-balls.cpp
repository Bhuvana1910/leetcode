class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int,int>m;
        map<int,int>s;
        vector<int>ans;
        for(int i=0;i<queries.size();i++){

             if(s.find(queries[i][0])!=s.end()){
              m[s[queries[i][0]]]--;
              if(m[s[queries[i][0]]]==0)
              m.erase(s[queries[i][0]]);
             }
             m[queries[i][1]]++;
             s[queries[i][0]]=queries[i][1];
             ans.push_back(m.size());
        }
        return ans;
    }
};