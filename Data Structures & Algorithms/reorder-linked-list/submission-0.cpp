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
    void reorderList(ListNode* head) {
        // strategy: interleave first half with reversed second half

        // identify midpoint
        int len = 0;
        ListNode *tmp = head;
        while (tmp) {
            tmp = tmp->next;
            len++;
        }
        if (len <= 2) return;

        int midIdx = (len + 1) / 2; // first half gets tiebreaker el so it never runs out when interleaving
        tmp = head;
        for (int i = 0; i < midIdx - 1; i++) tmp = tmp->next;

        ListNode *ptrMid = tmp->next;
        tmp->next = NULL; // disconnect second half

        // reverse second half of list
        ListNode *prev = NULL;
        ListNode *curr = ptrMid;
        while (true) {
            ListNode *oldNext = curr->next;
            curr->next = prev;
            if (!oldNext) break;

            prev = curr;
            curr = oldNext;
        }
        ListNode *tail = ptrMid;
        ptrMid = curr;

        // interleave halves
        ListNode *ptrL = head;
        ListNode *ptrR = ptrMid;
        
        while (ptrR) { // R will run out first because we lean L
            ListNode *nextL = ptrL->next;
            ListNode *nextR = ptrR->next;
            
            ptrL->next = ptrR;
            ptrR->next = nextL;

            ptrR = nextR;
            ptrL = nextL;
        }
    }
};
