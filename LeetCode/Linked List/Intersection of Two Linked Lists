class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1=headA;
        ListNode *tmp2=headB;
        
        while(tmp1!=tmp2){
            tmp1=tmp1!=NULL?tmp1->next:headA;
            tmp2=tmp2!=NULL?tmp2->next:headB;
        }
        if(tmp1!=NULL)
        return tmp1;
        else
            return NULL;
    }
};