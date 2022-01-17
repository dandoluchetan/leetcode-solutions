/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL,*curr,*nextnode;
        curr=head;
        while(curr){
            if(curr==head){
                nextnode=curr->next;
                prev=curr;
                curr=curr->next;
                prev->next=NULL;
            }
            else{
                nextnode=curr->next;
                curr->next=prev;
                prev=curr;
                curr=nextnode;
            }
        }
        return prev;
    }
};
