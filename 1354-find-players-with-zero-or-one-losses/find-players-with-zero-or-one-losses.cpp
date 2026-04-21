class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int,int>m;
        vector<int>f(1e5+1,0);
        for(int i=0;i<matches.size();i++){
            m[matches[i][0]]++;
            m[matches[i][1]]--;
            f[matches[i][0]]++;
            f[matches[i][1]]++;

        }
        vector<vector<int>>ans(2);
        for(auto i:m){
            cout<<i.first<<"->"<<i.second<<endl;
        }
        for(auto i:m){
            if(f[i.first]==i.second)
            ans[0].push_back(i.first);
            else if(f[i.first]-i.second==2)
            ans[1].push_back(i.first);
        }
        return ans;
        
    }
};