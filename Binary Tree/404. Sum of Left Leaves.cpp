/*
Given the root of a binary tree, return the sum of all left leaves.

Example 1:
Input: root = [3,9,20,null,null,15,7]

Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

//using one variable to calculate sum
class Solution {
public:
    void preorder(TreeNode* root,int& sum){
        if(!root)
            return;
        if(root->left && !root->left->left && !root->left->right)
            sum+=root->left->val;
        preorder(root->left,sum);
        preorder(root->right,sum);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int sum=0;
        if(!root)
            return sum;
        preorder(root,sum);
        return sum;    
    }
};

//using vector to capture leaves
class Solution1 {
public:
    void preorder(TreeNode* root,vector<int>& leftLeafArrayReference){
        if(!root)
            return;
        if(root->left && !root->left->left && !root->left->right)
            leftLeafArrayReference.push_back(root->left->val);
        preorder(root->left,leftLeafArrayReference);
        preorder(root->right,leftLeafArrayReference);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> leftLeafArray;
        preorder(root,leftLeafArray);
        return accumulate(leftLeafArray.begin(),leftLeafArray.end(),0);    
    }
};

