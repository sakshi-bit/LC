/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
         ListNode* fast = head;
        while(fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;
            if(slow==fast){
                fast = head;
                break;
            }
        }
        if(fast && fast->next){
            while(fast!=slow){
                fast =fast->next;
                slow = slow->next;
            }
            return fast;
        }
        return NULL;
    }
};