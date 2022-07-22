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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        int sum = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        
        while(l1 && l2){
            sum = l1->val + l2->val + carry;
            p->next = new ListNode(sum%10);
            carry = sum/10;
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        
        if(l2){
            l1=l2;
        }
        
        while(l1){
            sum = l1->val + carry;
            p->next = new ListNode(sum%10);
            carry = sum/10;
            p=p->next;
            l1=l1->next;
            
        }
        
        if(carry){
            p->next = new ListNode(carry);
        }
        
        return dummy->next;
        
    }
};