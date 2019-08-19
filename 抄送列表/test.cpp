#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

int main()
{
	std::string line;
	while (std::getline(std::cin, line)) //第一次的输入抓到line里
	{
		std::vector<std::string> names; //names里存放所有的数据
		size_t pos = 0;
		while (pos < line.length()) //位置如果大于等于了长度，那么证明找完了，双引号的情况从这里跳出
		{
			if (line[pos] == '\"') //找到双引号要处理双引号内部
			{
				size_t end = line.find("\"", pos + 1);
				names.push_back(line.substr(pos + 1, end - pos - 1)); //截取出来放到names里
				pos = end + 2;//跳掉后面的双引号和逗号
			} 
			else
			{
				size_t end = line.find(",", pos + 1);
				if (end == -1) //找不到逗号证明这是最后一个字符串了，直接存了这个字符串后跳出
				{
					names.push_back(line.substr(pos, line.size() - pos));
					break;
				} 
				names.push_back(line.substr(pos, end - pos));
				pos = end + 1; //跳掉后面的逗号
			}
		} 
		std::getline(std::cin, line);
		if (names.end() == std::find(names.begin(), names.end(), line))
		//std::find函数是在两个迭代器中间查找，最后一个参数是要找的值。
		//找到了返回对应迭代器，找不到就返回区间末尾的位置。本例中是end()。
		{
			printf("Important!\n"); //没找到
		} 
		else
		{
			printf("Ignore\n"); //找到了
		}
	} 
	return 0;
}