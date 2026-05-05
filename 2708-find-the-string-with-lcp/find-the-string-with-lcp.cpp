class Solution {
public:
    vector<vector<int>>find(string w){
    int n=w.size();
    vector<vector<int>>lcp(w.size(),vector<int>(w.size(),0));
    for(int i=0;i<n;i++){
    if(w[n-1]==w[i])
    lcp[n-1][i]=1;
    }
    for(int i=0;i<n;i++){
        if(w[n-1]==w[i])
        lcp[i][n-1]=1;
    }
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            if(w[i]==w[j])
            lcp[i][j]=1+lcp[i+1][j+1];
        }
    }
    return lcp;
    }
    string findTheString(vector<vector<int>>& lcp) {
        string w(lcp.size(),'$');
        int n=lcp.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(lcp[j][i]!=0){
                   w[i]=w[j];
                   break;
                }
            }
            vector<bool>forbidden(26,false);
            if(w[i]=='$')
            {
               for(int j=0;j<i;j++){
                 if(lcp[i][j] == 0){
                 forbidden[w[j]-'a'] = true;
                }
               } 
            for(int j=0;j<26;j++){
                if(!forbidden[j]){
                w[i]=(j+'a');
                break;
                }
            }
            if(w[i]=='$')
            return "";
            }
        }
        if(find(w)==lcp)
        return w;
        return "";
    }
};