class Solution {
public:
    int jumpFloor(int number) {
        if(number==0)
        {
            return 0;
        }
        int first=1;
        int second=1;
        for(int i=2;i<=number;i++)
        {
            int tmp=first+second;
            first=second;
            second=tmp;
        }
        return second;
    }
};