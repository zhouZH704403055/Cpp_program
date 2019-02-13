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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur||s.size()!=0)
        {
            while(cur)
            {
                s.push(cur);
                cur=cur->left;
            }
            TreeNode* top=s.top();
            s.pop();
            v.push_back(top->val);
            cur=top->right;
        }
        return v;
    }
};