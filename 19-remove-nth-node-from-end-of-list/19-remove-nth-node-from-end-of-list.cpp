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
        if(head==NULL||head->next==NULL)
            return NULL;
        ListNode*cur1=head;
        for(int i=0;i<n;i++){
            cur1=cur1->next;
        }
        if(cur1==NULL){
            ListNode*temp=head;
            head=head->next;
            delete temp;
            return head;
        }
        ListNode*cur2=head;
        while(cur1->next!=NULL){
            cur1=cur1->next;
            cur2=cur2->next;
        }
        ListNode*temp=cur2->next;
        cur2->next=cur2->next->next;
        delete temp;
        return head;
    }
};