class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        set<string>s;
        for(int i=0;i<queries.size();i++){
           for(int j=0;j<dictionary.size();j++){
            if(queries[i].size()!=dictionary[j].size())
            continue;
            int d=0;
            for(int k=0;k<queries[i].size();k++){
                if(queries[i][k]!=dictionary[j][k])
                d++;
            }
            if(d<=2 && s.find(queries[i])==s.end()){
            ans.push_back(queries[i]);
            break;
            }
           }
        }
        return ans;

    }
};