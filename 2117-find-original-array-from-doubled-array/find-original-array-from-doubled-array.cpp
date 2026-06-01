class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        unordered_map<int,int>m;
        vector<int>v;
        sort(changed.begin(),changed.end());
        for(int i=0;i<changed.size();i++)
        {
            if(changed[i]%2==0 && m.find((changed[i]/2))!=m.end())
            {
             m[(changed[i]/2)]--;
             if(m[(changed[i]/2)]==0)
             m.erase((changed[i]/2));
             v.push_back((changed[i]/2));
            }
            else
            {
                m[(changed[i])]++;
            }
            
        }
        if(m.size()>0)
        return {};
        else
        return v;  
    }
};