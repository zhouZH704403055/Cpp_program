class Solution {
public:
    bool rotateString(string A, string B) {
        if(A==B)
        {
            return true;
        }
        for(int i=0;i<A.size();i++)
        {
            reverse(A.begin(),A.begin()+1);
            reverse(A.begin()+1,A.end());
            reverse(A.begin(),A.end());
            if(A==B)
            {
                return true;
            }
        }
        return false;
    }
};