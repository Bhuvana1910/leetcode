class Solution {
public:
    void find(vector<vector<int>>&graph,int c,vector<int>&ans1){
        set<int>vis;
        deque<int>q;
        q.push_back(c);
        vis.insert(c);
        int steps=0;
        ans1[c]=steps;
        while(!q.empty()){
            int n=q.size();
            while(n--){
             int c=q.front();
             q.pop_front();
             ans1[c]=steps;
             for(int i=0;i<graph[c].size();i++){
                if(!vis.count(graph[c][i])){
                    vis.insert(graph[c][i]);
                    q.push_back(graph[c][i]);
                }
             }
            }
            steps++;
        }

    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>ans1(edges.size(),INT_MAX),ans2(edges.size(),INT_MAX);
        vector<vector<int>>graph(edges.size());
        for(int i=0;i<edges.size();i++){
            if(edges[i]!=-1){
                graph[i].push_back(edges[i]);
            }
        }
        find(graph,node1,ans1);
        find(graph,node2,ans2);
        int ans=INT_MAX,id=-1;
        for(int i=0;i<edges.size();i++){
            if(ans>max(ans1[i],ans2[i]))
            {
                ans=max(ans1[i],ans2[i]);
                id=i;
            }
        }
        return id;
    }
};