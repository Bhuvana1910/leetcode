class Solution {
public:
    int res;
    int dfs(vector<vector<int>>&graph,string &s,int c,int p){
        int l=0,sl=0;
        for(int i=0;i<graph[c].size();i++){
            if(p==graph[c][i])
            continue;
            int mdc=dfs(graph,s,graph[c][i],c);
            if(s[c]==s[graph[c][i]])
            continue;
            if(mdc>sl)
            sl=mdc;
            if(l<sl)
            swap(l,sl);
        }
        res=max({res,1+l+sl,l+1,1});
        return max(1+l,1);
    }
    int longestPath(vector<int>& parent, string s) {
        vector<vector<int>>graph(s.size());
        for(int i=1;i<parent.size();i++){
            graph[parent[i]].push_back(i);
            graph[i].push_back(parent[i]);
        }
        res=0;
        dfs(graph,s,0,-1);
        return res;

    }
};