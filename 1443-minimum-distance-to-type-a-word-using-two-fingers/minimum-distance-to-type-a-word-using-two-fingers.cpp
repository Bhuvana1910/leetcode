class Solution {
public:
    /*vector<vector<vector<int>>>dp;
    int find(string word,int i,int pf1,int pf2){
        if(i==word.size())
        return 0;
        int ch=word[i]-'A'+1;
        if(dp[i][pf1][pf2]!=-1)
        return dp[i][pf1][pf2];
        int f1=0,f2=0;
        if(i==0){
            f1=find(word,i+1,ch,pf2);
            f2=find(word,i+1,pf1,ch);
        }
        else{ 
            if(pf1!=0)
            f1=abs(m[(pf1-1)+'A'].first-m[word[i]].first)+abs(m[(pf1-1)+'A'].second-m[word[i]].second);
            f1+=find(word,i+1,ch,pf2);
            if(pf2!=0)
            f2=abs(m[(pf2-1)+'A'].first-m[word[i]].first)+abs(m[(pf2-1)+'A'].second-m[word[i]].second);
            f2+=find(word,i+1,pf1,ch);

        }
        return dp[i][pf1][pf2]=min(f1,f2);

    }*/
    map<char,pair<int,int>>m;
    int minimumDistance(string word) {
        int k=0;
        while(k<26){
        for(int i=0;i<5;i++){
            for(int j=0;j<6;j++){
                m['A'+k]={i,j};
                k++;
                if(k>=26)
                break;
            }
        }
        }
        /*dp.assign(word.size(),vector<vector<int>>(27,vector<int>(27,-1)));
        return find(word,0,0,0);*/
        vector<vector<vector<int>>>dp(word.size(),vector<vector<int>>(27,vector<int>(27,1000000)));
        for(int i=word.size()-1;i>=0;i--){
            for(int j=0;j<27;j++){
                for(int k=0;k<27;k++){
                    int f1=0,f2=0;
                    int ch=word[i]-'A'+1;
                    if(i==0){
                    f1=dp[i+1][ch][k];
                    f2=dp[i+1][j][ch];
                    }
                    else{ 
            if(j!=0)
            f1=abs(m[(j-1)+'A'].first-m[word[i]].first)+abs(m[(j-1)+'A'].second-m[word[i]].second);
            if(i+1<word.size())
            f1+=dp[i+1][ch][k];
            if(k!=0)
            f2=abs(m[(k-1)+'A'].first-m[word[i]].first)+abs(m[(k-1)+'A'].second-m[word[i]].second);
            if(i+1<word.size())
            f2+=dp[i+1][j][ch];
        }
        dp[i][j][k]=min(f1,f2);

                }
            }
        }
        return dp[0][0][0];


    }
};