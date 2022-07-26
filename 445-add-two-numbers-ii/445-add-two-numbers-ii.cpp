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
    void make_equal(ListNode* &l1,ListNode* &l2){
        ListNode* p1=l1;
        ListNode* p2=l2;
        while(p1 || p2){
            if(p1){
                p1=p1->next;
            }else{
            ListNode* n = new ListNode();
            n->val = 0;
            n->next = l1;
            l1=n;
            }
            if(p2){
                p2=p2->next;
            }else{
            ListNode* n = new ListNode();
            n->val = 0;
            n->next = l2;
            l2=n;
            }
            
        }
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL || l2==NULL){
            if(l1){
                return l1;
            }
                return l2;
            
        }
        
        make_equal(l1,l2);
        bool any_l2=true; //carry is there or not
        while(any_l2){
            any_l2 = false;
             ListNode* l1p=l1;
             ListNode* l2p=l2;
             ListNode* prev = NULL;
            while(l1p){
                int sum = l1p->val+l2p->val;
                l1p->val = sum%10; //this list will store sum
                l2p->val = sum/10;  //this list will store carry
                any_l2 = any_l2 || bool(l2p->val);
                prev = l2p;
                l1p=l1p->next;
                l2p=l2p->next;
            }
            
             prev->next = new ListNode();
            prev->next->val = 0;               //left shift for adding carry in sum
            
            //if carry is there next to l2 i.e if carry is present in l2 we have to add new node                 to perform addition with sum and carry
            if(l2->val){
                ListNode* n = new ListNode();
                n->val = 0;
                n->next = l1;
                l1=n;
            }else{ 
                l2=l2->next; //if no carry is there in the head we can remove the first node in                                  order to make the two list equal and remove extra nodes
            }
            
        }
        return l1; //return the list containing sum
    }
};