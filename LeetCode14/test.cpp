class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s="";
        int flag=1,j=0;
        if(strs.size()==0)
            return s;
        if(strs.size()==1)
            return strs[0];
        int min_len=strs[0].size();
        for(int i=1;i<strs.size();i++){
            if(min_len>strs[i].size())
                min_len=strs[i].size();
        }
        while(1){
            for(int i=1;i<strs.size();i++){
                if(strs[i][j]==strs[0][j])
                    flag=1;
                else{
                    flag=0;
                    break;
                }
            }
            if(flag==1){
                s+=strs[0][j];
                if(j<min_len-1)
                    j++;
                else
                    return s;
            }
            else
                return s;
        }
    }
};