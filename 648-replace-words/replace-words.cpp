class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string token;
        vector<string>t;
        while(getline(ss,token,' ')){
            t.push_back(token);
        }
        set<string>s;
        int l1=INT_MAX,l2=INT_MIN;
        for(int i=0;i<dictionary.size();i++){
            s.insert(dictionary[i]);
            int l=dictionary[i].size();
            l1=min(l1,l);
            l2=max(l2,l);
        }
        for(int i=0;i<t.size();i++){
            for(int j=l1;j<=l2;j++){
                if(t[i].size()<j){
                    break;
                }
                if(s.find(t[i].substr(0,j))!=s.end()){
                    t[i]=t[i].substr(0,j);
                    break;
                }
            }
        }
        string ans;
        for(int i=0;i<t.size();i++){
            if(i==t.size()-1)
            ans+=t[i];
            else{
            ans+=t[i];
            ans+=' ';
            }
        }
        return ans;
        
    }
};