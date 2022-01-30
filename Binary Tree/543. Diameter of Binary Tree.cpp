// https://leetcode.com/problems/diameter-of-binary-tree/

//maximum value of sum of heights of left-subtree and right-subtree of each node.
class Solution {
public:
    int preorder(TreeNode* root,vector<int>& arrayOfDistance){
        int l,r,height;
        if(!root)
            return 0; 
        int k1=preorder(root->left,arrayOfDistance);//height of child
        int k2=preorder(root->right,arrayOfDistance);//height of child
        l=k1+1;//l and r are height of current root( i.e including parent)
        r=k2+1;
        arrayOfDistance.push_back(k1+k2);
        height=(l>=r)?l:r;
        return height;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        vector<int> arrayOfDistance;
        int res=preorder(root,arrayOfDistance);
        return *max_element(arrayOfDistance.begin(),arrayOfDistance.end());
    }
};
