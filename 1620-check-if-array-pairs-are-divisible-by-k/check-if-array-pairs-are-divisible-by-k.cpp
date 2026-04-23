class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int>v(k,0);
        for(int &nums:arr){
            int r=(nums%k+k)%k;
            v[r]++;
        }
        if(v[0]%2!=0)
         return false;
        for(int i=1;i<=k/2;i++){
            int c=k-i;
            if(v[c]!=v[i])
             return false;
        }
        return true;
    }
};