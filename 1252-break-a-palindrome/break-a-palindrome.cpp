class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n=palindrome.size();
        if(palindrome.size()==1)
        return "";
        bool f=false;
        for(int i=0;i<palindrome.size();i++){
            if(palindrome[i]!='a'){
                if(!(n%2==1 && i==(n/2)) )
                {
                    cout<<i<<" "<<palindrome[i]<<endl;
                    palindrome[i]='a';
                    f=true;
                    break;
                }
            }
        }
        if(!f)
        palindrome[n-1]='b';
        return palindrome;

    }
};