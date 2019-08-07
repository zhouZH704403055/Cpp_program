class Solution {
public:
	void oddInOddEvenInEven(std::vector<int>& arr, int len) {
		long i = 0, j = 1;
		while(i < len && j < len){
			if((arr[i] % 2) == 0) 
			{ 
				i += 2; 
				continue; 
			}//偶数位上寻找非偶数
			if((arr[j] % 2) != 0) 
			{ 
				j += 2; continue; 
			}//奇数位上寻找非奇数
				swap(arr[i], arr[j]);
		}
	}
};