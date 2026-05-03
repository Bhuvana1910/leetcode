class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set<int>vis;
        vis.insert(0);
        deque<int>q;
        q.push_back(0);
        while(!q.empty()){
            int f=q.front();
            q.pop_front();
            for(int i=0;i<rooms[f].size();i++){
                if(!vis.count(rooms[f][i])){
                vis.insert(rooms[f][i]);
                q.push_back(rooms[f][i]);
                }
            }

        }
        return vis.size()==rooms.size();
    }
};