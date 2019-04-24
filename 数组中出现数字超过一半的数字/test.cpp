class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int flag=0;
        int num=numbers[0];
        for(auto e:numbers)
        {
            if(e==num)
            {
                flag++;
            }
            else{
                flag--;
                if(flag==0)
                {
                    num=e;
                    flag=1;
                }
            }
        }
        int count=0;
        for(auto e:numbers)
        {
            if(e==num)
            {
                count++;
            }
        }
        if((count<<1)>numbers.size())
        {
            return num;
        }
        return 0;
    }
};