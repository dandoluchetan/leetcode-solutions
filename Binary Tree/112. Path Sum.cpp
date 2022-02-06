// https://leetcode.com/problems/path-sum/

class Solution {
public:
    //can be named preorder too........
    void dfs(TreeNode* root, int sum, int& targetSum, bool& flag){
        if(!root)
            return;
        sum=sum+root->val;
        if(!root->left && !root->right){
            if(sum==targetSum)
                flag=true;
            return;
        }
        dfs(root->left,sum,targetSum,flag);
        dfs(root->right,sum,targetSum,flag);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        int sum=0;
        bool flag=false;
        dfs(root,sum,targetSum,flag);
        return flag;
    }
};
