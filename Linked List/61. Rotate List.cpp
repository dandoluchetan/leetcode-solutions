/*
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]

Constraints:
The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        auto curr=head;
        int length=0;
        while(curr){
            length++;
            curr=curr->next;
        }
        curr=head;
        k=k%length;//key is to reduce no. of rotations by taking the mod because if no. of rotations is divisible by length then the list remains the same;
        if(k>0){
            k=length-k-1;
            while(k>0){
                k--;
                curr=curr->next;
            }
            ListNode* temp=curr->next;
            ListNode* newhead=temp;
            curr->next=NULL;
            while(temp->next){
                temp=temp->next;
            }
            temp->next=head;
            return newhead;
        }
        return head;
    }
};
/*
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return NULL;
        if(!head->next)
            return head;
        auto curr=head;
        int length=0;
        while(curr){
            length++;
            curr=curr->next;
        }
        curr=head;
        k=k%length;//key is to reduce no. of rotations by taking the mod because if no. of rotations is divisible by length then the list remains the same;
        while(k>0){
            if(!curr->next->next){
                curr->next->next=head;
                head=curr->next;
                curr->next=NULL;
                curr=head;
                k--;
                continue;
            }
            curr=curr->next;
        }
        return head;
    }
};
*/
