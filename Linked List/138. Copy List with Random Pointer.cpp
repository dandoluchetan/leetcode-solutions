/*
A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. 
None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]
 
Constraints:
0 <= n <= 1000
-104 <= Node.val <= 104
Node.random is null or is pointing to some node in the linked list.
*/
class Solution {
public:
    Node* newhead_link=new Node(0);
    void insert(int x){
        Node* dummy=new Node(x);
        dummy->val=x;
        dummy->next=NULL;
        if(newhead_link->next==NULL){
            newhead_link->next=dummy;
        }
        else{
            auto curr=newhead_link->next;
            while(curr->next)
                curr=curr->next;
            curr->next=dummy;
        }
    }
    Node* copyRandomList(Node* head) {
        auto temp=head;
        Node *copytemp,*copytemp2,*temp2=head;
        if(!head)
            return NULL;
        while(temp){
            insert(temp->val);
            temp=temp->next;
        }
        Node* copyhead=newhead_link->next;
        temp=head;
        int i=0;//iterate through the original list
        while(temp){
            int j=i;
            copytemp=copyhead;
            temp2=head;
            while(j>0){
                copytemp=copytemp->next;
                j--;
            }
            if(temp->random==NULL){
                copytemp->random=NULL;
                temp=temp->next;
                i++;
                continue;
            }
            copytemp2=copyhead;
            int p=0;
            while(temp2){
                if(temp2==temp->random)
                    break;
                temp2=temp2->next;
                p++;
            }
            while(p>0){
                copytemp2=copytemp2->next;
                p--;
            }
            copytemp->random=copytemp2;
            temp=temp->next;
            i++;
        }
        return copyhead;
    }
};
