class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(-1);
        ListNode* ptr = temp;

        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ptr->next = l1;
                ptr = l1;
                l1 = l1->next;
            } else {
                ptr->next = l2;
                ptr = l2;
                l2 = l2->next;
            }
            if (l1) {
                ptr->next = l1;
            }

            if (l2) {
                ptr->next = l2;
            }
        }

        return temp->next;
    }
};