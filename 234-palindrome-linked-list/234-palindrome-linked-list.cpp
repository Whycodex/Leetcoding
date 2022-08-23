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
    ListNode*reverselist(ListNode*head){
        if(head==NULL||head->next==NULL)
            return head;
        ListNode*prev=NULL;
        ListNode*cur=head;
        while(cur!=NULL){
            ListNode*next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return true;
        ListNode*slow=head,*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*temp=slow->next;
        slow->next=NULL;
        ListNode*cur1=head;
        ListNode*cur2=reverselist(temp);
        while(cur1!=NULL&&cur2!=NULL){
            if(cur1->val!=cur2->val)
                return false;
            cur1=cur1->next;
            cur2=cur2->next;
        }
        return true;
    }
};