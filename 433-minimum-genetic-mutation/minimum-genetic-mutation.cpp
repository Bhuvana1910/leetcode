class Solution {
public:
    vector<char> genes = {'A','C','G','T'}; 
    unordered_map<string, int>b;
    map<pair<string,int>,int>m;
    int find(string c,string e,int mask){
        if(c==e)
        return 0;
        if(m.count({c,mask}))
        return m[{c,mask}];
        int ans=100000007;
        for(int i=0;i<c.size();i++){
            char cc=c[i];
            for(int j=0;j<genes.size();j++){
                if(genes[j]==cc)
                continue;
                c[i]=genes[j];
                if(b.count(c))
                {
                if(!(mask & (1<<b[c])))
                ans=min(ans,1+find(c,e,mask|(1<<b[c])));

                }

            }
            c[i]=cc;
        }
         return m[{c,mask}]=ans;
    
    }
    int minMutation(string startGene, string endGene, vector<string>& bank) {
    b.clear();
    for(int i=0;i<bank.size();i++)
     b[bank[i]]=i;
    if(!b.count(endGene))
    return -1;
    int ans=find(startGene,endGene,0);
    if(ans==100000007)
    return -1;
    return ans;
    }
};