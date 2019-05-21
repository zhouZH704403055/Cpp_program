#include<iostream>
#include<vector>

int main()
{
    int n=0;
    while(std::cin>>n)
    {
        std::vector<int> array(n);
        for(int i=0;i<n;i++)
        {
            std::cin>>array[i];
        }
        size_t result=0;
        for(int i=1;i<n-1;i++)
        {
            if((array[i]>array[i-1]&&array[i]>array[i+1])||(array[i]<array[i-1]&&array[i]<array[i+1]))
            {
                result++;
            }
            if(i!=n-3)
            {
                i++;
            }
        }
        std::cout<<result+1<<std::endl;
    }
    return 0;
}