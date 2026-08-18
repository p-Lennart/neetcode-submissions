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
    struct Comp {
        bool operator()(const ListNode *a, const ListNode *b) const {
            // by default pq is a max-heap with comparator=std::less<T>
            // greater -> min-heap
            return a->val > b->val;
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode *, vector<ListNode *>, Comp> frontiers;
        for (ListNode *front : lists) frontiers.push(front);

        ListNode dummy(0);
        ListNode *ptr = &dummy;

        while (!frontiers.empty()) {
            ListNode *nxt = frontiers.top();
            frontiers.pop();
            if (nxt->next) frontiers.push(nxt->next);
            
            ptr->next = nxt;
            ptr = nxt;
        }

        return dummy.next;
    }
// private:
//     ListNode* popNext(vector<ListNode**> &listPtrs) {
//         int minVal = 10000 + 1;
//         int argMin = -1;

//         for (int i = 0; i < listPtrs.size(); i++) {
//             ListNode *node = *(listPtrs[i]);
//             if (!node) continue;
//             if (node->val > minVal) continue;
//             minVal = node->val;
//             argMin = i;
//         }

//         if (argMin == -1) return NULL;

//         ListNode *popped = *(listPtrs[argMin]);
//         *(listPtrs[argMin]) = popped->next;
//         return popped;
//     }
};