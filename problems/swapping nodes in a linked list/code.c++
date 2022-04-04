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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode*p=head,*q=head,*r=head;
        int c=0;
        while(p!=NULL)
        {
          c++;
            p=p->next;
        }
        for(int i=0; i<k-1; i++)
        {
            r=r->next;
          }
        for(int i=0; i<c-k; i++)
        {
            q=q->next;
         }
        swap(q->val,r->val);
        return head;
    }
};