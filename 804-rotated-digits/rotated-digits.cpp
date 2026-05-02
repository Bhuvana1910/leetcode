class Solution {
public:
    bool check(string s){
        bool f=false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='3'||s[i]=='4'||s[i]=='7')
            return false;
            if(s[i]=='2'||s[i]=='5'||s[i]=='6'||s[i]=='9')
            f=true;
        }
        if(f)
        return true;
        return false;
    }
    int rotatedDigits(int n) {
        int c=0;
        for(int i=1;i<=n;i++){
            string s=to_string(i);
            if(check(s))
            c++;
        }
        return c;
    }
};