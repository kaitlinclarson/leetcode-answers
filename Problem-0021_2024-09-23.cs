// Runtime: 59ms | 73.29%
// Memory:  42.16MB | 32.63%

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode list1, ListNode list2) {
        if (list1 == null) {
            return list2;
        } else if (list2 == null) {
            return list1;
        } else {
            ListNode newNode;
            if (list1.val < list2.val) {
                newNode = list1;
                newNode.next = MergeTwoLists(list1.next, list2);
            } else {
                newNode = list2;
                newNode.next = MergeTwoLists(list1, list2.next);
            }
            return newNode;
        }
    }
}