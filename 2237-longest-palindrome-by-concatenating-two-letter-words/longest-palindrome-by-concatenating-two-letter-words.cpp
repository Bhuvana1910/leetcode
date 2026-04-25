class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0,f=0;
        map<string,int>m;
        for(int i=0;i<words.size();i++){
            string t=words[i];
            reverse(t.begin(),t.end());
            if(m.find(t)!=m.end()){
                ans+=2;
                m[t]--;
                if(m[t]==0)
                m.erase(t);
            }
            else{
            m[words[i]]++;
            }
        }
        for(auto i:m){
            string t=i.first;
            if(t[0]==t[1])
            {
                f++;
                break;
            }
        }
        if(f)
        ans+=1;
        return ans*2;
    }
};