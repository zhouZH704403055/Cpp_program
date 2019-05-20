class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> result;
        if(sum<3)
        {
            return result;
        }
        int small=1;
        int big=2;
        int end=(sum+1)>>1;
        int _sum=3;
        while(small<end)
        {
            if(_sum==sum)
            {
                vector<int> tmp;
                for(int i=small;i<=big;i++)
                {
                    tmp.push_back(i);
                }
                result.push_back(tmp);
            }
            while(small<end&&_sum>sum)
            {
                _sum-=small;
                small++;
                if(_sum==sum)
                {
                    vector<int> tmp;
                    for(int i=small;i<=big;i++)
                    {
                        tmp.push_back(i);
                    }
                    result.push_back(tmp);
                }
            }
            big++;
            _sum+=big;
        }
        return result;
    }
};