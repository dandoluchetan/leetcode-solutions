/*
Given the root of a binary tree, return the preorder traversal of its nodes' values.

Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]
*/
class Solution {
public:
    void preorder(TreeNode* root,vector<int> &k){
            if(!root)
                return;
            k.push_back(root->val);
            preorder(root->left,k);
            preorder(root->right,k);
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> k;
        preorder(root,k);
        return k;
    }
};
