/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes
(i.e., only nodes themselves may be changed.)

Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]
*/

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode *one=head,*two,*prev;
        ListNode *dummy;
        while(one && one->next){
            two=one->next;
            dummy=two->next;
            two->next=one;
            one->next=dummy;
            if(head==one){//The key to this problem is once a pair is swapped the link of prev swapped pair must be updated to the new pair swap.
                prev=one;
                head=two;
            }
            else{
                prev->next=two;
                prev=one;
            }
            one=one->next;
        }
        return head;
    }
};
