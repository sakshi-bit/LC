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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        
        ListNode* p = new ListNode(0);
        p->next = head;
        head = p;
        ListNode* l = head->next;
        ListNode* r = head->next;
        while(r){
            if(l->val==r->val){
                r=r->next;
            }
            else if(l->next==r){
                p->next = l;
                p=l;
                l=r;
            }
            else{
                l=r;
            }
        }
        if(l->next==NULL){
            p->next=l;
        }else{
            p->next = NULL;
        }
        
        return head->next;
    }
};