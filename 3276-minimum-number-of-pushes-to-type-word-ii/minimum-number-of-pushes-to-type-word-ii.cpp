class Solution {
public:
    int minimumPushes(string word) {
     vector<int>ans(26,0);
     for(int i=0;i<word.size();i++){
        ans[word[i]-'a']++;
     }
     sort(ans.begin(),ans.end(),greater<int>());
     map<int,int>m;
     int c=2,res=0;
     for(int i=0;i<26;i++){
       if(ans[i]==0)
       break;
       if(c>9)
       c=2;
       m[c]++;
       res+=(ans[i]*m[c]);
       c++;

     }
     return res;

    }
};