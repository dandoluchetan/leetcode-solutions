/*You are given the head of a linked list, and an integer k.
Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:
Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

Constraints:
The number of nodes in the list is n.
1 <= k <= n <= 105
0 <= Node.val <= 100/*
You are given the head of a linked list, and an integer k.
*/

class Solution {
public:
    void insert(ListNode* first,ListNode* temp){
        temp->next=first->next;
        first->next=temp;
    }
    ListNode* swapNodes(ListNode* head, int k) {
        if(!head->next){
            return head;
        }
        int i=1;
        ListNode* curr=head,*first=NULL,*second=NULL;
        for(curr=head;curr!=NULL;curr=curr->next){
            if(i==k){
                first=curr;
                second=head;
            }
            else if(first && second){
                second=second->next;
            }
            i++;
        }
        int x=second->val;
        second->val=first->val;
        first->val=x;
        return head;
    }
};
