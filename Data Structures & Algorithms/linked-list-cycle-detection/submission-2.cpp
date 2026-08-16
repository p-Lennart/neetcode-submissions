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
    bool hasCycle(ListNode* head) {
        if (!head || !(head->next)) return false;
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (true) {
            slow = slow->next;
            fast = fast->next;
            if (!slow || !fast || !(fast->next)) return false;
            if (slow == fast || slow == fast->next) return true;
            fast = fast->next;
        }

        return false;
    }
};
