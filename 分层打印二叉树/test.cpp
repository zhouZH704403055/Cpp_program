/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
        vector<vector<int> > Print(TreeNode* pRoot) {
            vector<vector<int>> result;
            if(pRoot==nullptr)
            {
                return result;
            }
            queue<TreeNode*> q;
            q.push(pRoot);
            while(!q.empty())
            {
                vector<int> tmp;
                int end=q.size();
                for(int i=0;i<end;i++)
                {
                    TreeNode* cur=q.front();
                    q.pop();
                    if(cur->left)
                    {
                        q.push(cur->left);
                    }
                    if(cur->right)
                    {
                        q.push(cur->right);
                    }
                    tmp.push_back(cur->val);
                }
                result.push_back(tmp);
            }
            return result;
        }
};