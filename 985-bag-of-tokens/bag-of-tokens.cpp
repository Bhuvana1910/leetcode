class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0)
        return 0;
        int s=0,ans=0,i=0,j=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        if(power<tokens[0])
        return ans;
        while(i<=j){
            if(power>=tokens[i])
            {
                power-=tokens[i];
                s++;
                i++;
            }
            else if(s){
                  power+=tokens[j];
                  s--;
                  j--;
                }
            else 
            break;
            ans=max(ans,s);

        }
        return ans;

    }
};