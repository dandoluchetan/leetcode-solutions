/*
You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]
*/

//used hashmap,one can can do it without hashmap by 1. finding middle node,2.from middle node(not includimg) reverse the 2nd half,3.merge 1st half and 2nd half by storing the next node of each 1st half element.
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head->next){
            ListNode* curr=head;
            unordered_map<int,ListNode*> order;
            int i=1;
            while(curr){
                order[i]=curr;
                curr=curr->next;
                i++;
            }
            int length=i-1;
            ListNode *temp;
            i=1;
            while(i<=length/2){
                temp=order[i]->next;
                order[i]->next=order[length+1-i];
                order[length+1-i]->next=temp;
                i++;
            }
            if(length%2)
                order[i]->next->next->next=NULL;
            else
                order[i]->next->next=NULL;
        }
    }
};
