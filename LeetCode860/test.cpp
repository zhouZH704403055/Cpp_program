class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num_5=0;
        int num_10=0;
        for(auto e:bills)
        {
            if(e==5)
            {
                num_5++;
            }
            else if(e==10)
            {
                num_10++;
                if(num_5==0)
                {
                    return false;
                }
                else
                {
                    num_5--;
                }
            }
            else if(e==20)
            {
                if(num_10==0)
                {
                    if(num_5<3)
                    {
                        return false;
                    }
                    else
                    {
                        num_5-=3;
                    }
                }
                else
                {
                    if(num_5>0)
                    {
                        num_5--;
                        num_10--;
                    }
                    else
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};