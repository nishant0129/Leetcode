/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode*p=head,*q=head;
        if(head==NULL ||  head->next==NULL)
        {
             return head;
            }
        while(q!=NULL && q->next!=NULL)
        {
            q=q->next->next;
            p=p->next;
        }
        return p;
    }
};