#include<iostream>

long long factorial(int x)
{
    long long ret=1;
    for(int i=2;i<=x;i++)
    {
        ret*=i;
    }
    return ret;
}

int main()
{
    int m=0;
    int n=0;
    std::cin>>m;
    std::cin>>n;
    if(m<=0||n<=0)
    {
        std::cout<<0;
        return 0;
    }
    std::cout<<(factorial(m+n)/(factorial(m)*factorial(n)));
    return 0;
}