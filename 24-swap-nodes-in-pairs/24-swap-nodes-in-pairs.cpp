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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode* p1 = head;
        ListNode* p2 = head->next;
        ListNode* newHead = p2;
        ListNode* x = p2->next;
        p2->next = p1;
        p1->next = swapPairs(x);
        return newHead;
    }
};