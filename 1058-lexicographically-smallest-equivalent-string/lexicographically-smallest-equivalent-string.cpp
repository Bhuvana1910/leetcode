class Solution {
public:
    char dfs(vector<vector<char>>&graph,int c){
        char t=c+'a';
        deque<int>q;
        set<int>vis;
        q.push_back(c);
        vis.insert(c);
        while(!q.empty()){
            char s=q.front();
            t=min(t,(char)(q.front()+'a'));
            q.pop_front();
            for(int i=0;i<graph[s].size();i++){
                if(!vis.count(graph[s][i]))
                {
                    vis.insert(graph[s][i]);
                    q.push_back(graph[s][i]);
                }
            }
        }
        return t;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<vector<char>>graph(26);
        for(int i=0;i<s1.size();i++){
            int u = s1[i] - 'a';
            int v = s2[i] - 'a';
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<baseStr.size();i++){
            baseStr[i]=dfs(graph,baseStr[i]-'a');
        }
        return baseStr;
    }
};