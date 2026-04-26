class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,vector<int>>r,c;
        int ans=0;
        for(int i=0;i<buildings.size();i++){
            r[buildings[i][0]].push_back(buildings[i][1]);
            c[buildings[i][1]].push_back(buildings[i][0]);
        }
        for(auto &i : r){
            sort(i.second.begin(), i.second.end());
        }
        for(auto &i : c){
         sort(i.second.begin(), i.second.end());
        }
        for(int i=0;i<buildings.size();i++){
            if(r[buildings[i][0]].size()<=2 && c[buildings[i][1]].size()<=2 )
            continue;
            vector<int>&r1=r[buildings[i][0]];
            vector<int>&r2=c[buildings[i][1]];
            auto it1=lower_bound(r1.begin(),r1.end(),buildings[i][1]);
            auto it2=upper_bound(r1.begin(),r1.end(),buildings[i][1]);
            auto it3=lower_bound(r2.begin(),r2.end(),buildings[i][0]);
            auto it4=upper_bound(r2.begin(),r2.end(),buildings[i][0]);
            if(it2==r1.end() || it4==r2.end())
            continue;
            int i1=it1-r1.begin(),i2=it3-r2.begin();
            if(i1-1>=0 && i2-1>=0)
            ans++;
            
        }
        return ans;
    }
};