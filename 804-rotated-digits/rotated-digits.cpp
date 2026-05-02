class Solution {
public:
    int check(int i){
        if(i==0)
        return 0;
        int r=check(i/10);
        if(r==2)
        return 2;
        int d=i%10;
        int v_d=0;
        if(d==0 || d==1|| d==8 )
        v_d=0;
        else if(d==2 || d==5 || d==6 || d==9)
        v_d=1;
        else
        return 2;
        if(r==0 && v_d==0)
        return 0;
        return 1;


    }
    int rotatedDigits(int n) {
        int c=0;
        for(int i=1;i<=n;i++){
            
            if(check(i)==1)
            c++;
        }
        return c;
    }
};