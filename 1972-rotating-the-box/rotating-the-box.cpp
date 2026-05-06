class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& b) {
        vector<vector<char>>boxGrid(b[0].size(),vector<char>(b.size()));
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                  boxGrid[j][i]=b[i][j];
            }
        }
        cout<<boxGrid.size()<<" "<<boxGrid[0].size()<<endl;
        int n=boxGrid[0].size();
        for(int i=0;i<boxGrid.size();i++){
            for(int j=0;j<boxGrid[0].size()/2;j++){
                swap(boxGrid[i][j],boxGrid[i][n-1-j]);
            }
        }
        for(int i=0;i<boxGrid[0].size();i++){
            int ob=boxGrid.size(),c=0;
            for(int j=boxGrid.size()-1;j>=0;j--){
              if(boxGrid[j][i]=='*'){
                int k=ob-1;
                while(k>=0 && c){
                   boxGrid[k][i]='#';
                   c--;
                   k--;
                }
                ob=j;
              }
              else if(boxGrid[j][i]=='#'){
              boxGrid[j][i]='.';
              c++;
              }
              else
              boxGrid[j][i]='.';
            }
            if(c){
                int k=ob-1;
                while(k>=0 && c){
                   boxGrid[k][i]='#';
                   c--;
                   k--;
                }  
            }
        }
        return boxGrid;
    }
};