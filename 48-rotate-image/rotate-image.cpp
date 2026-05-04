class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        int n=a.size();
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j>i){
            int t=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n/2;j++){
            swap(a[i][j],a[i][n-1-j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    } 
    }
};