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
    ListNode* recursive(ListNode* l1, ListNode* l2 , int carry=0){

        if(!l1 && !l2 && !carry)
            return 0 ;

        int a = l1?l1->val:0;
        int b = l2?l2->val:0;
        int sum = a+b+carry;
        int digit= sum%10;
        carry= sum/10;

        ListNode* ans = new ListNode(digit);
        ans->next= recursive(l1?l1->next:l1 , l2?l2->next:l2 , carry);
        return ans;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return recursive(l1,l2);
    }
};