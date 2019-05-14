class Solution {
public:
	int rectCover(int number) {
		int first = 1;
		int second = 1;
		int result = number;
		for (int i = 2; i <= number; i++)
		{
			result = first + second;
			first = second;
			second = result;
		}
		return result;
	}
};