class Solution {
public:
    int fibon(int a,int b,int n)
    {
        if(n==3)
            return a+b;
        return fibon(b,a+b,n-1);
    }
    int climbStairs(int n) {
        if(n==1)
            return 1;
        else if(n==2)
            return 2;
        else
            return fibon(1,2,n);
        
    }
};