/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false
*/
class Solution {
public:
    void preorder(TreeNode* a,TreeNode* b, bool& flag){
        if(!a && !b)
            return;
        if((!a && b)||(!b && a)){
            flag=false;
            return;
        }
        if(a->val!=b->val)
            flag=false;
        preorder(a->left,b->left,flag);
        preorder(a->right,b->right,flag);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool flag=true;
        preorder(p,q,flag);
        return flag;
    }
};
