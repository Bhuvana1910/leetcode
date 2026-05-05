class Solution {
public:
    vector<int>parent;
    int findparent(int u){
        if(parent[u]==u)
        return u;
        return parent[u]=findparent(parent[u]);
    }
    void unions(char s1,char s2){
        int x=findparent(s1-'a');
        int y=findparent(s2-'a');
        if(x<y)
        parent[y]=x;
        else
        parent[x]=y;
       
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.assign(26,0);
        for(int i=0;i<26;i++)
        parent[i]=i;
        for(int i=0;i<s1.size();i++)
        unions(s1[i],s2[i]);
        for(int i=0;i<26;i++)
        findparent(i);

        for(int i=0;i<baseStr.size();i++){
            baseStr[i]= baseStr[i] = (char)(findparent(baseStr[i] - 'a') + 'a');

        }
        return baseStr;
    }
};