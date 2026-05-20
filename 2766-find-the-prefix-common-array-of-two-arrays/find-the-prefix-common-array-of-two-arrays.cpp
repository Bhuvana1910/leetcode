class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int>af(51,0),bf(51,0);
        vector<int>c;
        for(int i=0;i<A.size();i++){
            af[A[i]]++;
            bf[B[i]]++;
            int cn=0;
            for(int i=0;i<=50;i++){
                if(af[i]==0)
                continue;
                if(af[i]==bf[i])
                cn++;
            }
            c.push_back(cn);

        }
        return c;
    }
};