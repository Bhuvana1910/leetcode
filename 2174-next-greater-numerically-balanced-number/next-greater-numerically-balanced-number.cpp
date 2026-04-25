class Solution {
public:
    bool canPossible(int n){
    vector<int> freq(10, 0);

    while(n){
        freq[n % 10]++;
        n /= 10;
    }

    for(int d = 0; d <= 9; d++){
        if(freq[d] != 0 && freq[d] != d)
            return false;
    }
    return true;
}
    int nextBeautifulNumber(int n) {
        vector<int>ans;
        for(int i=n+1;i<=10000000;i++){
            if(canPossible(i))
            return i;

        }
        
        return -1;
    }
};