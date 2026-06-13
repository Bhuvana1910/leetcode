class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string ans;
        for(int i=0;i<words.size();i++){
            int c=0;
            for(int j=0;j<words[i].size();j++){
                c+=(weights[words[i][j]-'a']);
            }
            c%=26;
            char t='a'+(25-c);
            ans+=t;
        }
        return ans;
    }
    
};