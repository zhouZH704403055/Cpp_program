class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root==nullptr)
        {
            return v;
        }
        std::stack<TreeNode*> s;
        TreeNode* cur=root;
        while(cur||s.size()!=0)
        {
            while(cur)
            {
                v.push_back(cur->val);
                s.push(cur);
                cur=cur->left;
            }
            TreeNode* top=s.top();
            s.pop();
            cur=top->right;
        }
        return v;
    }
};