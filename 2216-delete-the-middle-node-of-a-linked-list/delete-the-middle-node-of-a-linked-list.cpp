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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode*s=head,*p=NULL;
        ListNode*f=head;
        int c=0;
        while(s){
            s=s->next;
            c++;
        }
        if(c==1)
        return NULL;
        s=head;
        while(f && f->next ){
            p=s;
            s=s->next;
            f=f->next->next;
        }
        ListNode*n=NULL;
        if(s!=NULL && s->next)
        n=s->next;
        p->next=n;
        return head;

    }
};