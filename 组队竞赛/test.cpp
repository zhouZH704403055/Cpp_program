#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	int n;
	while(std::cin>>n)
	{
		size_t sum=0;
		std::vector<int> array(3*n,0);
		for(int i=0;i<(3*n);i++)
		{
			std::cin>>array[i];
		}
		std::sort(array.begin(),array.end());
		for(int i=3*n-2;i>=n;i-=2)
		{
			sum+=array[i];
		}
		std::cout<<sum<<std::endl;
	}
	return 0;
}