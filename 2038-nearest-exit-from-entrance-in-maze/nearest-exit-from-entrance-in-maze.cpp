class Solution {
public:
    vector<vector<int>>v={{-1,0},{1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        set<pair<int,int>>vis;
        vis.insert({entrance[0],entrance[1]});
        int steps=0;
        deque<pair<int,int>>q;
        q.push_back({entrance[0],entrance[1]});
        while(!q.empty()){
          int n=q.size();
          while(n--){
            int r=q.front().first;
            int c=q.front().second;
            q.pop_front();
            for(int i=0;i<v.size();i++){
                int nr=r+v[i][0],nc=c+v[i][1];
                if(nr<0 || nr>=maze.size() || nc<0 || nc>=maze[0].size()){
                if(steps==0)
                continue;
                return steps;
                }
                if(!vis.count({nr,nc}) && maze[nr][nc]=='.')
                {
                    vis.insert({nr,nc});
                    q.push_back({nr,nc});
                }
            }
          }
          steps++;  
        }
        return -1;
    }
};