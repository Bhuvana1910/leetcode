class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>m;
        for(int i=0;i<matches.size();i++)
        {
            int ans=matches[i][1];
            m[ans]++;
        }
        set<int>l,w;
        for(int i=0;i<matches.size();i++)
        {
            int a=matches[i][0];
            int b=matches[i][1];
            if(m[b]==1)
            l.insert(b);
            if(m.find(a)==m.end())
            w.insert(a);
        }
        vector<int>win(w.begin(),w.end());
        vector<int>loose(l.begin(),l.end());
        return{win,loose};
    }
};