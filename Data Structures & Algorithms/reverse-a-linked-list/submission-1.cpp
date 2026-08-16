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
    ListNode* reverseList(ListNode* head) {
        // more efficient take 2 after naive solution 1
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr) {
            auto oldNext = curr->next;
            curr->next = prev;

            prev = curr;
            curr = oldNext;
        }

        return prev;
    }
};
