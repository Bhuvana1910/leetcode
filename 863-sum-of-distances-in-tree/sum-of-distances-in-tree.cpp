class Solution {
public:
    vector<int>count;
    int res;
    int find(vector<vector<int>>& graph,int c,int p,int d){
        int nodes=1;
        res+=d;
        for(int i=0;i<graph[c].size();i++){
            if(graph[c][i]==p)
            continue;
            nodes+=find(graph,graph[c][i],c,d+1);

        }
        count[c]=nodes;
        return nodes;
    }
    void dfs(vector<vector<int>>& graph,int c,int p,vector<int>&res){
        for(int i=0;i<graph[c].size();i++){
            if(graph[c][i]==p)
            continue;
            res[graph[c][i]]=res[c]-count[graph[c][i]]+(graph.size()-count[graph[c][i]]);
            dfs(graph,graph[c][i],c,res);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int>ans(n);
        set<int>s;
        vector<vector<int>>graph(n);
        count.assign(n,0);
        for(int i=0;i<edges.size();i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);

        }    
        res=0;    
        find(graph,0,-1,0);
        ans[0]=res;
        dfs(graph,0,-1,ans);
        return ans;


    }
};