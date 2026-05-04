class Solution {
public:
    int dfs( vector<vector<int>>& graph, vector<bool>& hasApple,int c,int p){
        int has=0;
        if(hasApple[c])
        has=1;
        int total=0;
        for(int i=0;i<graph[c].size();i++){
            if(p==graph[c][i])
            continue;
            total+=dfs(graph,hasApple,graph[c][i],c);

        }
        if(p!=-1 &&(has==1 || total>0))
        total+=2;
        return total;

    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>graph(n);
        for(int i=0;i<edges.size();i++){
         graph[edges[i][0]].push_back(edges[i][1]);
         graph[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(graph,hasApple,0,-1);
    }
};