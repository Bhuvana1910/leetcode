class Solution {
public:
    bool dfs(vector<vector<int>>& graph,int s,int d,set<int>&vis){
        if(s==d)
        return true;
        vis.insert(s);
        for(int i=0;i<graph[s].size();i++){
            if(!vis.count(graph[s][i])){
            if(dfs(graph,graph[s][i],d,vis))
            return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }
        set<int>vis;
        return dfs(graph,source,destination,vis);
    }
};