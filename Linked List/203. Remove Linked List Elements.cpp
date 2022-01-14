/*Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:
Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]
Example 2:

Input: head = [], val = 1
Output: []
Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
*/
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
    ListNode* removeElements(ListNode* head, int val){
        ListNode *temp1=new ListNode;
        ListNode *temp;
        while(head!=NULL && head->val==val)
            head=head->next;
        if(head==NULL){
            return head;
        }
        temp1=head;
        while(temp1->next!=NULL){
            temp=temp1->next;
            while(temp!=NULL && temp->val==val){
                temp=temp->next;
            }
            temp1->next=temp;
            if(temp==NULL){
                return head;
            }
            temp1=temp1->next;
        }
        return head;
    }
};
