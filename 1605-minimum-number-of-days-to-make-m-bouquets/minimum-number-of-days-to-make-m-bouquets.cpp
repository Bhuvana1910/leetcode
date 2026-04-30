class Solution {
public:
    bool check(vector<int>& b, int m, int k,int mid){
        int f=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=mid)
            f++;
            else
            f=0;
            if(f==k){
            m--;
            f=0;
            }
            if(m==0){
            return true;
            }

        }
        return m==0;
    }
    int minDays(vector<int>& b, int m, int k) {
        int l=*min_element(b.begin(),b.end()),h=*max_element(b.begin(),b.end());
        if(b.size()<(m*1LL*k))
        return -1;
        int ans=0;
        while(l<=h){
            int mid=(l+h)/2;
            if(check(b,m,k,mid)){
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans==0 ?-1 :ans;
    }
};