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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyNode = new ListNode(123);
        if(head==NULL){
            return head;
        }
        while(head){
            ListNode* forward = head->next;
            ListNode* temp = dummyNode;
            while(temp->next && temp->next->val<head->val){
                temp=temp->next;
            }
            
            head->next = temp->next;
            temp->next = head;
            head=forward;
            
        }
        return dummyNode->next;
    }
};