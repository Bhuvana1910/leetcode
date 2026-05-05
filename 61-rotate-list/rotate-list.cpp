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
    int lsize(ListNode* head){
        int c=0;
        ListNode*temp=head;
        while(temp){
         c++;
         temp=temp->next;
        }
        return c;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int s=lsize(head);
        if(s==0)
        return head;
        k=k%s;
        ListNode*temp=head;
        ListNode*tail=head;
        while(temp){
            temp=temp->next;
            if(temp)
            tail=temp;
        }
        while(k--){
            temp=head;
            while(temp){
               if(temp->next==tail)
               break;
               temp=temp->next;
            }
            temp->next=NULL;
            tail->next=head;
            head=tail;
            tail=temp;
        }
        return head;
    }
};