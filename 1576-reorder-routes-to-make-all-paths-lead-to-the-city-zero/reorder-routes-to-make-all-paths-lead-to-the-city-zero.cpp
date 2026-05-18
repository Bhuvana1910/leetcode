class Solution {
public:
    int ans;
    void find(vector<vector<pair<int,int>>>&graph,int c,int p){
        for(int i=0;i<graph[c].size();i++){
            if(graph[c][i].first!=p){
                if(graph[c][i].second==1)
                ans++;
                find(graph,graph[c][i].first,c);
            }

        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i=0;i<connections.size();i++){
            int a=connections[i][0],b=connections[i][1];
            graph[a].push_back({b,1});
            graph[b].push_back({a,0});
        }
        ans=0;
        find(graph,0,-1);
        return ans;
    }
};