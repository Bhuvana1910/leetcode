class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        map<int,int>m;
        set<int> d;  
        map<int,int>si;
        vector<int>ans(rains.size(),-1);
        for(int i=0;i<rains.size();i++){
            if(rains[i]==0){
            d.insert(i);
            ans[i]=1;
            }
            else{
             m[rains[i]]++;
             if(si.find(rains[i])==si.end())
             si[rains[i]]=i;

             if(m[rains[i]]>1){
                if(!d.empty()){
                    auto it = d.upper_bound(si[rains[i]]);

                    if (it == d.end())
                        return {};

                    int dd = *it;
                    ans[dd] = rains[i];
                    d.erase(it);
                    si[rains[i]]=i;
                }
                else 
                return {};
             }
            }
        }
        return ans;
        
    }
};