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
    ListNode* oddEvenList(ListNode* head) {
        if((head==NULL || head->next==NULL)||head->next->next==NULL){
            return head;
        }
        ListNode* o = head;
        ListNode* e = head->next;
        
        while(e!=NULL && e->next!=NULL){
            ListNode* x=e->next;
            e->next = e->next->next;
            x->next = o->next;
            o->next = x;
            o=o->next;
            e=e->next;
        }
        return head;
    }
};