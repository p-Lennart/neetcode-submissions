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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = popNextNode(&list1, &list2);
        ListNode *ptr = head;

        if (!head) return NULL;

        while (list1 || list2) {
            ptr->next = popNextNode(&list1, &list2);
            ptr = ptr->next;
        }
        ptr->next = NULL;
        return head;
    }
private:
    ListNode *popNextNode(ListNode **ptr1, ListNode **ptr2) {
        ListNode *list1 = *ptr1;
        ListNode *list2 = *ptr2;

        int ln = 0;
        if (!list1 && !list2)               ln = 0;
        else if (!list1)                    ln = 2;
        else if (!list2)                    ln = 1;
        else if (list1->val <= list2-> val) ln = 1;
        else                                ln = 2;

        ListNode *pick = NULL;
        if (ln == 1) {
            pick = list1;
            *ptr1 = list1->next;
        } else if (ln == 2) {
            pick = list2;
            *ptr2 = list2->next;
        }
        return pick;
    }
};
