/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right,
and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]

Constraints:
The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        ListNode *curr,*temp,*prev=NULL,*one_less_lefthead=NULL,*lefthead;
        int n=1;
        curr=head;
        while(n<left){
            n++;
            prev=curr;
            curr=curr->next;
        }
        if(prev)
            one_less_lefthead=prev;
        lefthead=curr;
        while(curr && n<right+1){
            n++;
            temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        if(!one_less_lefthead)
            head=prev;
        else
            one_less_lefthead->next=prev;
        lefthead->next=temp;
        return head;
    }
};
