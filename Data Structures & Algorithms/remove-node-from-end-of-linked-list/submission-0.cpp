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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *tmp = head;
        while (tmp) {
            tmp = tmp->next;
            len++;
        }
        
        int removeIdx = len - n;
        
        ListNode *prev = NULL;
        ListNode *curr = head;

        for (int i = 0; i < removeIdx; i++) {
            prev = curr;
            curr = curr->next;
        }

        if (prev) {
            prev->next = curr->next;
        } else {
            head = curr->next;
        }
        curr->next = NULL;

        return head;
    }
};
