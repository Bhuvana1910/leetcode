class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        map<string,int>m1;
        for(int i=0;i<arr1.size();i++){
            string s=to_string(arr1[i]);
            string a;
            for(int j=0;j<s.size();j++){
                a+=s[j];
                m1[a]=j+1;
            }
        }
        for(int i=0;i<arr2.size();i++){
            string s=to_string(arr2[i]);
            string a;
            for(int j=0;j<s.size();j++){
                a+=s[j];
                if(m1.find(a)!=m1.end()){
                    ans=max(ans,m1[a]);
                }
            }
        }
        return ans;
        
    }
};