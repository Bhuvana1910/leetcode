class Solution {
public:
    vector<vector<vector<int>>>dp;
    int rd(string s, int i, bool tight, bool isval) {
    if (i == s.size()) {
        return isval ? 1 : 0;
    }
    if(dp[i][tight][isval]!=-1)
    return dp[i][tight][isval];
    int ub = (tight ? s[i] - '0' : 9);
    int res = 0;
    for (int d = 0; d <= ub; d++) {

        if (d == 3 || d == 4 || d == 7)
            continue;

        bool f = isval;  

        if (d == 2 || d == 5 || d == 6 || d == 9)
            f = true;

        res += rd(s, i + 1, (tight && d == ub), f);
    }
    return dp[i][tight][isval]=res;
}
    int rotatedDigits(int n) {
        string s=to_string(n);
        dp.assign(s.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return rd(s,0,1,false);
    }
};