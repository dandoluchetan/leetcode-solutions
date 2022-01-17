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