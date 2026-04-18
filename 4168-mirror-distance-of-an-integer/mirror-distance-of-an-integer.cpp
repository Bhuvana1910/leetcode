class Solution {
public:
    int mirrorDistance(int n) {
        string b=to_string(n);
        reverse(b.begin(),b.end());
        int nb=stoi(b);
        return(abs(n-nb));
    }
};