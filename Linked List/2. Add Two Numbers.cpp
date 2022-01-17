/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
class Solution {
public:
    ListNode* newheadLink=new ListNode();
    //inserting at the end of list
    void insert(int x){
        ListNode* dummy=new ListNode();
        dummy->val=x;
        dummy->next=NULL;
        if(newheadLink->next==NULL)
            newheadLink->next=dummy;
        else{
            ListNode* curr=newheadLink;
            while(curr->next){
                curr=curr->next;
            }
            curr->next=dummy;
        }
    }
    ListNode* addTwoNumbers(ListNode* head1, ListNode* head2) {
        int sum=0,carry=0,res;
        ListNode* l1=head1,*l2=head2;
        while(l1 || l2){
            if(l2==NULL){
                res=carry+l1->val;
                l1=l1->next;
                carry=res/10;
                sum=res%10;
                insert(sum);
                continue;
            }
            if(l1==NULL){
                res=carry+l2->val;
                l2=l2->next;
                carry=res/10;
                sum=res%10;
                insert(sum);
                continue;
            }
            else{
                res=carry+l1->val+l2->val;
                l1=l1->next;
                l2=l2->next;
                carry=res/10;
                sum=res%10;
                insert(sum);
                continue;
            }
        }
        if(carry>0)
            insert(carry);
        return newheadLink->next;
    }
};
