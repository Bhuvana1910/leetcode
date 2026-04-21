class Solution {
public:
    
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string token;
        while(getline(ss,token,' ')){//while(ss>>token)
         words.push_back(token);
        }
        map<char,string>m;
        map<string,char>n;
        if(words.size()!=pattern.size())
        return false;
        for(int i=0;i<pattern.size();i++){
            if(m.find(pattern[i])!=m.end())
            {
                if(words[i]!=m[pattern[i]])
                return false;
            }
            if(n.find(words[i])!=n.end())
            {
                if(pattern[i]!=n[words[i]])
                return false;
            }
            m[pattern[i]]=words[i];
            n[words[i]]=pattern[i];
        }
        return true;
    }
};