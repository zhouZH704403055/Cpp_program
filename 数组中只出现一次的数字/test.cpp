class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        int ret=0;
        for(auto e: data)
        {
            ret^=e;
        }
        int bit=1;
        int n=0;
        while((ret&bit)==0&&n<sizeof(int)*8)
        {
            bit<<=1;
            n++;
        }
        *num1=0;
        *num2=0;
        for(auto e:data)
        {
            if((e&bit)==0)
            {
                (*num1)^=e;
            }
            else{
                (*num2)^=e;
            }
        }
    }
};