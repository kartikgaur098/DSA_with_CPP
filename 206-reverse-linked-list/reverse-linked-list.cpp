class Solution{
    public:
    // Recursive method
    // ListNode* reverseList(ListNode* &prev , ListNode* &curr){
    //     if(curr==NULL){
    //         return prev ;
    //     }

    //     ListNode* forward = curr->next;
    //     curr->next=prev;
    //     prev=curr;
    //     curr=forward;
    //     return reverseList(prev , curr);
    // }
    // ListNode* reverseList(ListNode *head){
    //     ListNode* prev=NULL;
    //     ListNode* curr=head;

    //     ListNode* newHead = reverseList(prev,curr);
    //     return newHead;
    // }


    // Loop Method 
       ListNode* reverseList(ListNode* head){
        ListNode* prev= NULL;
        ListNode* curr= head;

        while(curr!=NULL){
            ListNode* forward = curr->next;
            curr->next=  prev;
            prev=curr;
            curr=forward;
        }
        return prev;
       }
};