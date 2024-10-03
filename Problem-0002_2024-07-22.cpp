// Runtime: 34ms | 8.20%
// Memory:  77.55MB | 43.88%

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
        ListNode* head {nullptr};
        ListNode* temp {nullptr};
        int value {0};

        value = l1->val + l2->val;
        head = new ListNode(value % 10);
        temp = head;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 || l2) {
            value = (value > 9);

            if (l1) {
                value += l1->val;
                l1 = l1->next;
            }
            
            if (l2) {
                value += l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(value % 10);
            temp = temp->next;
        }

        if (value > 9) {
            temp->next = new ListNode(1);
        }

        return head;
    }
};