/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if(pListHead==nullptr)
        {
            return nullptr;
        }
        ListNode* quick=pListHead;
        ListNode* slow=pListHead;
        while(quick&&k--)
        {
            quick=quick->next;
        }
        if(quick==nullptr&&k!=0)
        {
            return nullptr;
        }
        while(quick)
        {
            quick=quick->next;
            slow=slow->next;
        }
        return slow;
    }
};