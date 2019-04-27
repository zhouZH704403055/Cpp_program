/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot2==nullptr||pRoot1==nullptr)
        {
            return false;
        }
        return IsSubtree(pRoot1,pRoot2)||HasSubtree(pRoot1->left,pRoot2)||HasSubtree(pRoot1->right,pRoot2);
    }
    bool IsSubtree(TreeNode* pRoot1,TreeNode* pRoot2)
    {
        if(pRoot2==nullptr)
        {
            return true;
        }
        if(pRoot1==nullptr||(pRoot1->val!=pRoot2->val))
        {
            return false;
        }
        return IsSubtree(pRoot1->left,pRoot2->left)&&IsSubtree(pRoot1->right,pRoot2->right);
    }
};