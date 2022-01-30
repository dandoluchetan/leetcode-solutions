// https://leetcode.com/problems/binary-tree-tilt/


//preorder traversal, add left+right+root and store in a temp, and at the same time update root->val as absolute difference of l & r that are calculated in the same instance.
//after that return the temp. 
class Solution {
public:
    int preorderTilt(TreeNode* root){
        if(!root)
            return 0;
        int l=preorderTilt(root->left);
        int r=preorderTilt(root->right);
        int temp=root->val+l+r;
        root->val=abs(l-r);
        return temp;
    }//at the end of this function the tree would look like[6,2,7,0,0,null,0] for the input [4,2,9,3,5,null,7];
    
    void preorderSum(TreeNode* root,int& sum){
        if(!root)
            return;
        sum+=root->val;
        preorderSum(root->left,sum);
        preorderSum(root->right,sum);
    }
    int findTilt(TreeNode* root) {
        int sum=0;
        int res=preorderTilt(root);
        preorderSum(root,sum);
        return sum;
    }
};
