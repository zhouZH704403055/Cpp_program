class Solution {
public:
    int Fibonacci(int n) {
        if(n==0)
        {
            return 0;
        }
        int first=1;
        int second=1;
        for(int i=2;i<n;i++)
        {
            int tmp=first+second;
            first=second;
            second=tmp;
        }
        return second;
    }
};