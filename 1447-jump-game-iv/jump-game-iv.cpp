class Solution {
public:
    map<int,vector<int>>m;
    int minJumps(vector<int>& arr) {
        m.clear();
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        deque<int>q;
        q.push_back(0);
        set<int>vis;
        vis.insert(0);
        int s=0;
        while(!q.empty()){
         int n=q.size();
         while(n--){
            int t=q.front();
            q.pop_front();
            if(t==arr.size()-1)
            return s;
            if(t-1>=0 && !vis.count(t-1)){
                q.push_back(t-1);
                vis.insert(t-1);
            }
            if(t+1<arr.size() && !vis.count(t+1)){
                q.push_back(t+1);
                vis.insert(t+1);
            }
            if(m.find(arr[t])!=m.end()){
            for(int i=0;i<m[arr[t]].size();i++){
                if(!vis.count(m[arr[t]][i])){
                q.push_back(m[arr[t]][i]);
                vis.insert(m[arr[t]][i]);
            }
            }
            m[arr[t]].clear();
            }
         }
         s++;
        }
        return -1;


        
    }
};