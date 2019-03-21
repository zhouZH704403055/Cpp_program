class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) 
            return 0;
        int n = haystack.length();
        int m = needle.length();
        int i = 0;
        int j = 0;
        auto b = make_unique<int[]>(m + 1);
        preprocess(needle, b.get());
        
        while (i < n) {
            while(j != -1 && haystack[i] != needle[j]) 
                j = b[j];
            i++;
            j++;
            if (j == m) return i - j;
        }
        return -1;
    }
    void preprocess(const string& needle, int* b) {
        b[0] = -1;
        
        for (size_t i = 0; i < needle.length(); ++i) {
            int j = b[i]; // 长度为 i 的 border 宽度为 j
            while(j != -1 && needle[i] != needle[j]) 
                j = b[j];
            b[i+1] = j + 1;
        }
    }
};