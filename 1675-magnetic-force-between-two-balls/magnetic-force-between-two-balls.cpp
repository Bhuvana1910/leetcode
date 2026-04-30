class Solution {
public:
    bool check(vector<int>& position, int m,int mid){
        m--;
        if(m==0)
        return true;
        int i=0;
        while(true){
            auto it=lower_bound(position.begin(),position.end(),position[i]+mid);
            if(it==position.end())
            return false;
            m--;
            if(m==0)
            return true;
            i = it - position.begin();
        }
        return false;

    }
    int maxDistance(vector<int>& position, int m) {
        int l=1,h=*max_element(position.begin(),position.end())-*min_element(position.begin(),position.end());
        sort(position.begin(),position.end());
        int ans=0;
        while(l<=h){
        int mid=(l+h)/2;
        if(check(position,m,mid)){
            ans=mid;
            l=mid+1;
        }
        else
        h=mid-1;
        }
        return ans;
    }
};