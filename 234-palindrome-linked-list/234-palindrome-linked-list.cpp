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
    bool isPalindrome(ListNode* head) {
        ListNode*p=head,*q=head;
        stack<int>st;
        while(p)
        {
            st.push(p->val);
            p=p->next; 
        }
        
        int i;
        while(q!=NULL)
        {
           i=st.top();
            st.pop();
            if(i!=q->val)
            {
              return false;
            }
            q=q->next;
        }
        return true;
    }
// };
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode *slow=head,*fast=head,*prev,*tmp;
//         while(fast&&fast->next)
//         {
//             slow=slow->next;
//             fast=fast->next->next;
//         }
//         prev=slow;
//         slow=slow->next;
//         prev->next=NULL;
//         // reverse half of list
//         prev=NULL;
//         while(slow)
//         {
//             tmp=slow->next;
//             slow->next=prev;
//             prev=slow;
//             slow=tmp;
//         }
//         fast=head; slow=prev; // since slow will be pointing at last node 
//         while(slow)
//         {
//             if(slow->val!=fast->val) return false ;
//             slow=slow->next; fast=fast->next;
//         }
//         return true ;
//     }
};