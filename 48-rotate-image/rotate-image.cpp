class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix.size();j++){
                if(i<j)
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<matrix.size();i++){
            int j=0;
            while(j<(n/2)){
                swap(matrix[i][j],matrix[i][n-1-j]);
                j++;
            }
        }
    }
};