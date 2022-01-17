/**
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Constraints:
The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
 */
class Solution {
public:
    
    ListNode* sortedHead=new ListNode();//here the created node is not pointed to NULL but sortedHead->next is NULL
    void insert(int x){// inserting the node at the end of llist
        ListNode* temp=new ListNode();
        if(sortedHead->next==NULL){
            sortedHead->next=temp;
            temp->val=x;
            temp->next=NULL;
        }
        else{
            ListNode* curr;//Here curr is not NULL but curr->next isnt accesible;
            curr=sortedHead;
            while(curr->next){
                curr=curr->next;
            }
            curr->next=temp;
            temp->val=x;
            temp->next=NULL;
        }
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *one=list1, *two=list2;
        if(one==NULL && two==NULL){
            return NULL;
        }
        while(one || two){
            if(two==NULL){
                insert(one->val);
                one=one->next;
                continue;
            }
            if(one==NULL){
                insert(two->val);
                two=two->next;
                continue;
            }
            if(one->val > two->val){
                insert(two->val);
                two=two->next;
                continue;
            }
            if(one->val < two->val){
                insert(one->val);
                one=one->next;
                continue;
            }
            if(one->val==two->val){
                insert(one->val);
                insert(two->val);
                one=one->next;
                two=two->next;
                continue;
            }
        }
        return sortedHead->next;
    }
};
