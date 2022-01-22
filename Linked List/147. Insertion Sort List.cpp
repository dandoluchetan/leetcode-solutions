/*
Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

The steps of the insertion sort algorithm:
Insertion sort iterates, consuming one input element each repetition and growing a sorted output list.
At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list and inserts it there.
It repeats until no input elements remain.
The following is a graphical example of the insertion sort algorithm.
The partially sorted list (black) initially contains only the first element in the list. One element (red) is removed from the input data and inserted in-place into the sorted list with each iteration.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
*/
class Solution {
public:
    
    void insert(ListNode* temp1,ListNode* curr1){
        curr1->next=temp1->next;
        temp1->next=curr1;
    }
    
    ListNode* insertionSortList(ListNode* head) {
        ListNode* curr,*prev,*temp;
        curr=head->next;
        prev=head;
        temp=head;
        
        while(curr){
            if(curr->val>=prev->val){
                curr=curr->next;
                prev=prev->next;
                continue;
            }
            while(temp){
                if(temp==head && (temp->val > curr->val)){
                    prev->next=curr->next;
                    curr->next=head;
                    head=curr;
                    temp=head;
                    curr=prev->next;
                    break;
                }
                if(temp->next->val > curr->val){
                    prev->next=curr->next;
                    insert(temp,curr);
                    temp=head;
                    curr=prev->next;
                    break;
                }
                else{
                    temp=temp->next;
                }
            }
        }
        return head;
    }
};
