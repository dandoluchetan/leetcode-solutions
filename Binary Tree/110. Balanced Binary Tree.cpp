//https://leetcode.com/problems/balanced-binary-tree/
class Solution {
public:
    int preorder(TreeNode* root,bool& flag){
        if(!root)
            return 0;
        int l=preorder(root->left,flag)+1;
        int r=preorder(root->right,flag)+1;
        if(abs(l-r)>1)
            flag=false;
        return (l>=r)?l:r;
    }
    
    bool isBalanced(TreeNode* root) {
        bool flag=true;
        int res=preorder(root,flag);
        return flag;
    }
};
