class Solution {
public:
    int m=1000000007;
    int lengthAfterTransformations(string s, int t) {
        vector<long long>ans(26,0);
        for(int i=0;i<s.size();i++){
            ans[s[i]-'a']+=(1*1LL);
        }
        while(t--){
            vector<long long>next(26,0);
            for(int i=0;i<26;i++){
                if(ans[i]==0){
                continue;
                }
                if(i==25){
                    next[0]+=(ans[i])%m;
                    next[1]+=(ans[i])%m;
                    ans[i]=0;
                }
                else{
                    next[i+1]+=(ans[i])%m;
                    ans[i]=0;
                }
               
            }
            ans=next;
        }
        long long c=0;
        for(int i=0;i<26;i++)
        c=(c+ans[i])%m;
        return int(c);
    }
};