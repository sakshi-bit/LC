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
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* forward = NULL;
        
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
    ListNode* cutInHalve(ListNode* head){
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        if(fast->next!=NULL){
            slow=slow->next;
        }
        
        ListNode* t = slow->next;
        slow->next = NULL;
        return t;
    }
    
    ListNode* merge(ListNode* head){
        ListNode* h = cutInHalve(head);
        h = reverse(h);
        ListNode* p = head;
        
        while(h!=NULL){
            ListNode* x =h->next;
            h->next = p->next;
            p->next =h;
            p=p->next->next;
            h=x;
        }
        return head;
    }

    void reorderList(ListNode* head) {
        merge(head);
    }
};