//https://leetcode.com/problems/count-complete-tree-nodes/
class Solution {
public:
    /*
    void preorder(TreeNode* root,int& length) {
        if(root==NULL)
            return;
        length++;
        preorder(root->left,length);
        preorder(root->right,length);
    }
    int countNodes(TreeNode* root) {
        int length=0;
        preorder(root, length);
        return length;
    }*/
    
    //any algo is fine both same complexities
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        int leftHeight=0,rightHeight=0;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        
        while(l){
            leftHeight++;
            l=l->left;
        }
        while(r){
            rightHeight++;
            r=r->right;
        }
        
        if(leftHeight==rightHeight){
            return pow(2,leftHeight+1)-1;
        }
        
        return 1+countNodes(root->left)+countNodes(root->right);
    }    
};
