class Solution {
public:
    int rd(string s, int i, bool tight, bool isval) {
    if (i == s.size()) {
        return isval ? 1 : 0;
    }

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

    return res;
}
    int rotatedDigits(int n) {
        string s=to_string(n);
        return rd(s,0,1,false);
    }
};