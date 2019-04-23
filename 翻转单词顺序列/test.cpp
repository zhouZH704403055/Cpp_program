class Solution {
public:
    string ReverseSentence(string str) {
        auto start=str.begin();
        auto end=start;
        while(end!=str.end())
        {
            if(*end==' ')
            {
                reverse(start,end);
                start=end+1;
                end=start;
            }
            else{
                end++;
            }
        }
        reverse(start,end);
        reverse(str.begin(),str.end());
        return str;
    }
};