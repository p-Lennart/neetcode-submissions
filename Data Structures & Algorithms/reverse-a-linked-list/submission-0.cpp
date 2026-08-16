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
        if (!head || ! (head->next)) return head;

        ListNode *tail = head;
        while (tail->next != NULL) tail = tail->next;

        ListNode *prev = head;
        ListNode *curr = head->next;
        head->next = NULL;

        while (true) {
            ListNode *nxt = curr->next;
            curr->next = prev;
            if (curr == tail) break;
            prev = curr;
            curr = nxt;
        }

        return tail;
    }
};
