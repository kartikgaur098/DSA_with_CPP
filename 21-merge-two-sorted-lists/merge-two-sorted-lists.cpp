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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode* ans = new ListNode(-1); // Dummy node
        ListNode* mptr = ans;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                mptr->next = l1;
                l1 = l1->next;
            } else {
                mptr->next = l2;
                l2 = l2->next;
            }
            mptr = mptr->next;
        }

        while (l1) {
            mptr->next = l1;
            l1 = l1->next;
            mptr = mptr->next;
        }

        while (l2) {
            mptr->next = l2;
            l2 = l2->next;
            mptr = mptr->next;
        }

        return ans->next;
    }
};
