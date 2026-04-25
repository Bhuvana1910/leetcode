class Solution {
public:
    string toLower(string s) {
        for(char &c : s) c = tolower(c);
        return s;
    }
    
    string maskVowel(string s) {
        for(char &c : s){
            c = tolower(c);
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
                c = '*';
        }
        return s;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> lowerMap;
        unordered_map<string, string> vowelMap;

        
        for(string &w : wordlist){
            exact.insert(w);

            string lower = toLower(w);
            string masked = maskVowel(w);
            if(!lowerMap.count(lower))
                lowerMap[lower] = w;

            if(!vowelMap.count(masked))
                vowelMap[masked] = w;
        }

        vector<string> ans;

        for(string &q : queries){
            if(exact.count(q)){
                ans.push_back(q);
                continue;
            }

            string lower = toLower(q);
            if(lowerMap.count(lower)){
                ans.push_back(lowerMap[lower]);
                continue;
            }
            string masked = maskVowel(q);
            if(vowelMap.count(masked)){
                ans.push_back(vowelMap[masked]);
                continue;
            }
            ans.push_back("");
        }

        return ans;
    }
};