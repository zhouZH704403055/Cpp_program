/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        struct ListNode* temp;
        struct ListNode* l3;
        if(l1==NULL&&l2==NULL)
            return NULL;
        if(l1==NULL&&l2!=NULL) 
            return  l2;
        if(l1!=NULL&&l2==NULL) 
            return l1;
        l3=l1->val<=l2->val? l1:l2;
            temp=l3;
        if(l1->val<=l2->val) 
            l1=l1->next;
        else l2=l2->next;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                l3->next=l1;l3=l1;l1=l1->next;
            }
            else 
            {
                l3->next=l2;l3=l2;l2=l2->next;
            }
       
    }
    
    l3->next=l1?l1:l2;
    return temp;
    }
};