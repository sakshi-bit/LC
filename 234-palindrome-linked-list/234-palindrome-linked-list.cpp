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
    ListNode* cutInHalf(ListNode* head){
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast->next!=NULL && fast->next->next!=NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        if(fast->next!=NULL){
            slow=slow->next;
        }
        ListNode* t = slow->next;
        return t;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forward = NULL;
        
        while(curr!=NULL){
            forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* h = cutInHalf(head);
        h = reverse(h);
        
        while(h!=NULL){
        if(head->val!=h->val){
            return 0;
        }
            
        head = head->next;
        h = h->next;
        
    }
        return 1;
    }
};