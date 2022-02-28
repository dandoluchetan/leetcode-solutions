
//https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
/*
1. Algo is find a subtree such that p and q are in opposite sides to te root of the subtree.
2. Once the subtree is found then find minNode in bothe LHS and RHS subtree such that iteration will be done based on BST. 
*/
class Solution {
public:
    void findRightMin(TreeNode* newRoot,TreeNode* minNode,TreeNode* GTNode){
        if(newRoot->val==GTNode->val)
            return;
        if(newRoot->val>GTNode->val){
            if(newRoot->val<minNode->val)
                minNode=newRoot;
            findRightMin(newRoot->left,minNode,GTNode);
        }
        if(newRoot->val<GTNode->val){
            if(newRoot->val<minNode->val)
                minNode=newRoot;
            findRightMin(newRoot->right,minNode,GTNode);
        }
    }
    void findLeftMin(TreeNode* newRoot,TreeNode* minNode,TreeNode* LTNode){
        if(newRoot->val==LTNode->val)
            return;
        if(newRoot->val>LTNode->val){
            if(newRoot->val<minNode->val)
                minNode=newRoot;
            findLeftMin(newRoot->left,minNode,LTNode);
        }
        if(newRoot->val<LTNode->val){
            if(newRoot->val<minNode->val)
                minNode=newRoot;
            findLeftMin(newRoot->right,minNode,LTNode);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pNode, TreeNode* qNode) {
        TreeNode* temp=root;
        int p=pNode->val;
        int q=qNode->val;
        while((p>temp->val && q>temp->val) || (p<temp->val && q<temp->val)){
            if(p>temp->val && q>temp->val){
                temp=temp->right;
            }
            if(p<temp->val && q<temp->val){
                temp=temp->left;
            }
        }    
        TreeNode* minNode=temp;
        if(p<q){
            findLeftMin(temp,minNode,pNode);
            findRightMin(temp,minNode,qNode);
        }
        else{
            findLeftMin(temp,minNode,qNode);
            findRightMin(temp,minNode,pNode);
        }
        return minNode;
    }
};
