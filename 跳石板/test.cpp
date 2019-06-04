#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<cmath>

void Div(std::vector<int>& div,int num)
{
    for(int i=2;i<=sqrt(num);++i)
    {
        if(num%i==0)
        {
            div.push_back(i);
            if(i!=num/i)
            {
                div.push_back(num/i);
            }
        }
    }
}

int main()
{
    int n=0;
    int m=0;
    std::cin>>n>>m;
    std::vector<int> dp(m+1,INT_MAX);
    dp[n]=0;
    for(int i=n;i<=m;++i){
        if(dp[i]==INT_MAX)
        {
            continue;
        }
        std::vector<int> div;
        Div(div,i);
        for(int j=0;j<div.size();++j){
            if(div[j]+i<=m)
            {
                dp[div[j]+i]=std::min(dp[div[j]+i],dp[i]+1);
            }
        }
    }
    if(dp[n]==INT_MAX)
    {
        std::cout<<"-1"<<std::endl;
    }
    else
    {
        std::cout<<dp[m]<<std::endl;
    }
    return 0;
}