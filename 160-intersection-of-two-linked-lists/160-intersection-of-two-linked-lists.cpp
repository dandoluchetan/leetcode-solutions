/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* dupeA,*dupeB;
        dupeA=headA;
        dupeB=headB;
        if(!headA || !headB){
            return NULL;
        }
        int na=0,nb=0;
        while(dupeA){
            dupeA=dupeA->next;
            na++;
        }
        while(dupeB){
            dupeB=dupeB->next;
            nb++;
        }
        int diff=abs(na-nb);
        dupeA=headA;
        dupeB=headB;
        if(na>nb){
            while(diff--)
                dupeA=dupeA->next;
        }
        if(nb>na){
            while(diff--)
                dupeB=dupeB->next;
        }
        while(dupeA){
            if(dupeA==dupeB)
                return dupeA;
            dupeA=dupeA->next;
            dupeB=dupeB->next;
        }
        return NULL;
    }
};