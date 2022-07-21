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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* c1 = list1;
        ListNode* c2 = list2;
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        
        while(c1!=NULL && c2!=NULL){
            if(c1->val < c2->val){
                prev->next = c1;
                c1=c1->next;
            }else{
                prev->next = c2;
                c2=c2->next;
            }
            prev = prev->next;
        }
        if(c1!=NULL){
            prev->next = c1;
        }else{
            prev->next = c2;
        }
        
        return dummy->next;
    }
};