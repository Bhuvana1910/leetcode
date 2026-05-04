class Solution {
public:
    void find(vector<vector<int>>& graph,vector<vector<int>>& ans,vector<int>&temp,int v){
        temp.push_back(v);
        if(v==graph.size()-1){
            ans.push_back(temp);
        }
        for(int i=0;i<graph[v].size();i++){
            find(graph,ans,temp,graph[v][i]);
        }
        temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        find(graph,ans,temp,0);
        return ans;
    }
};