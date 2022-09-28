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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode*p=head,*q=head;
        int len=0;       
        while(p!=NULL)
        {
          len++;
          p=p->next;
        }
        p=head;
        len=len-n-1;
        if(len==-1) {
            return head->next;
        }
        while(len--)
        {
            p=p->next;
        }
        p->next=p->next->next;
      
        return head;
    }
};