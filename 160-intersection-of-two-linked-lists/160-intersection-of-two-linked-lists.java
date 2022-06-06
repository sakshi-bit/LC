/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        //boundary condition
        if(headA==null || headB==null)
            return null;
        
        ListNode a = headA;
        ListNode b = headB;
        
        while(a!=b){
        
        //stop when both lengths are different
            
            a=a==null?headA:a.next;
            b=b==null?headB:b.next;
        }
        return a;
    }
}