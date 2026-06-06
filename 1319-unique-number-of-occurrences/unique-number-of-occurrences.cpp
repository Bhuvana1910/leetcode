class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>m;
        for(int i=0;i<arr.size();i++)
        {
            m[arr[i]]++;
        }
        unordered_set<int>s;
        for(auto i:m)
        {
           int freq=i.second;
           if(s.find(freq)!=s.end())
           return false;
           s.insert(freq);
        }
        return true;
    }
};