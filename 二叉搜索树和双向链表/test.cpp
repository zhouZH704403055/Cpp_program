/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution 
{
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree==nullptr)
        {
            return nullptr;
        }
        TreeNode* NewList=nullptr;
        Convert(pRootOfTree,&NewList);
        TreeNode* Head=NewList;
        while(Head&&Head->left)
        {
            Head=Head->left;
        }
        return Head;
    }
    void Convert(TreeNode* pRootOfTree,TreeNode** NewList)
    {
        TreeNode* cur=pRootOfTree;
        if(pRootOfTree==nullptr)
        {
            return;
        }
        if(cur->left)
        {
            Convert(cur->left,NewList);
        }
        cur->left=*NewList;
        if(*NewList!=nullptr)
        {
            (*NewList)->right=cur;
        }
        *NewList=cur;
        if(cur->right)
        {
            Convert(cur->right,NewList);
        }
    }
};