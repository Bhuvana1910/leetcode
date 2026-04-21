class Solution {
public:
    void dfs(map<int,vector<int>>&m,vector<int>&ans,int s,set<int>&st){
        st.insert(s);
        vector<int>temp=m[s];
        for(int i=0;i<temp.size();i++){
            if(st.find(temp[i])==st.end())
            {
                ans.push_back(temp[i]);
                dfs(m,ans,temp[i],st);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int,vector<int>>m;
        for(int i=0;i<adjacentPairs.size();i++){
            m[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            m[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);        
        }
        vector<int>ans;
        int s;
        for(auto i:m){
            if(i.second.size()==1){
                s=i.first;
                break;
            }
        }
        set<int>st;
        ans.push_back(s);
        dfs(m,ans,s,st);
        return ans;
    }
};