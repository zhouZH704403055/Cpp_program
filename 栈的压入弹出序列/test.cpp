class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stk;
        int j=0;
        for(int i=0;i<pushV.size();i++)
        {
            stk.push(pushV[i]);
            while(!stk.empty()&&popV[j]==stk.top())
            {
                stk.pop();
                j++;
                if(stk.empty()&&j==popV.size())
                {
                    return true;
                }
            }
        }
        return false;
    }
};