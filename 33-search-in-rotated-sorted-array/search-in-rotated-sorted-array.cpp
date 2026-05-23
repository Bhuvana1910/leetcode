class Solution {
int bst(vector<int>& a, int t){
    int l=0,h=a.size()-1;
    while(l<=h){
        int m=l+(h-l)/2;
        if(a[m]==t)
         return m;
        else if(a[l]<=a[m]){
            if(a[l]<=t && t<=a[m])
             h=m-1;
            else
             l=m+1;
        }
        else{
            if(a[m]<t && t<=a[h])
             l=m+1;
            else
             h=m-1;
        }
         
    }
    return -1;
}
public:
    int search(vector<int>& nums, int target) {
        return bst(nums,target);
    }
};