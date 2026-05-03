class Solution {
public:
    void dfs(vector<vector<int>>& stones,int i,set<int>&vis){
        vis.insert(i);
        for(int j=0;j<stones.size();j++){
          if(!vis.count(j) && (stones[j][0]==stones[i][0] || stones[j][1]==stones[i][1]))
          dfs(stones,j,vis);
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int g=0;
        set<int>vis;
        for(int i=0;i<stones.size();i++){
            if(!vis.count(i)){
             dfs(stones,i,vis);
            g++;
            }
        }
        return stones.size()-g;
    }
};