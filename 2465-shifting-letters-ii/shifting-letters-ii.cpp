class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>v(s.size(),0);
        for(int i=0;i<shifts.size();i++){
            int l=shifts[i][0],r=shifts[i][1],d=shifts[i][2];
            if(d==1)
            {
                v[l]+=1;
                if(r+1<s.size())
                v[r+1]-=1;
            }
            else{
               v[l]-=1;
                if(r+1<s.size())
                v[r+1]+=1; 
            }
        }
        for(int i=1;i<s.size();i++)
        v[i]+=v[i-1];
        for(int i=0;i<s.size();i++){
            char c=s[i];
            v[i] = ((v[i] % 26) + 26) % 26;
            c=((s[i]-'a')+v[i])%26+'a';
            s[i]=c;

        }
        return s;
    }
};