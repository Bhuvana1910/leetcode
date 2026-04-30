class Solution {
public:
    bool check(vector<int>& quantities,int n,int m){
        int c=0;
        for(int i=0;i<quantities.size();i++){
            c+=(quantities[i]+m-1)/m;
        }
        return c<=n;
    
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
       int l=1,h=*max_element(quantities.begin(),quantities.end());
       int ans=0;
       while(l<=h){
        int m=(l+h)/2;
        if(check(quantities,n,m))
        {
            ans=m;
            h=m-1;
        }
        else
         l=m+1;
       }
       return ans;
    }
};