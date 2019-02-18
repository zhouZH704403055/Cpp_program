/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        TreeNode* prev=root;
        while(cur||s.size()!=0)
        {
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            TreeNode* top=s.top();
            if(top->right==NULL||top->right==prev)
            {
                result.push_back(top->val);
                prev=top;
                s.pop();
            }
            else
            {
                cur=top->right;
            }
        }
        return result;
    }
};