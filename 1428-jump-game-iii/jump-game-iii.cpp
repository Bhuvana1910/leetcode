class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<vector<int>>graph(arr.size());
        for(int i=0;i<arr.size();i++){
            if(i-arr[i]>=0)
            graph[i].push_back(i-arr[i]);
            if(i+arr[i]<arr.size())
            graph[i].push_back(i+arr[i]);

        }
        deque<int>q;
        q.push_back(start);
        set<int>vis;
        vis.insert(start);
        while(!q.empty()){
            int c=q.front();
            q.pop_front();
            if(arr[c]==0)
            return true;
            for(int i=0;i<graph[c].size();i++){
                if(!vis.count(graph[c][i])){
                    vis.insert(graph[c][i]);
                    q.push_back(graph[c][i]);

                }
            }
        }
        return false;
    }
};