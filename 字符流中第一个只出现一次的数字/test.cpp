class Solution
{
public:
  //Insert one char from stringstream
    Solution()
        :map(256,-1),index(0)
    {}
    void Insert(char ch)
    {
         if(map[ch]==-1)
         {
             map[ch]=index;
         }
        else{
            map[ch]=-2;
        }
        index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        char ch='#';
        int n=256;
        for(int i=0;i<256;i++)
        {
            if(map[i]!=-1&&map[i]!=-2)
            {
                if(map[i]<n)
                {
                    ch=i;
                    n=map[i];
                }
            }
        }
        return ch;
    }
private:
    vector<int> map;
    int index;
};