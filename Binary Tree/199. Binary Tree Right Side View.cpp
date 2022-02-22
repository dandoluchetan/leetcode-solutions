//https://leetcode.com/problems/binary-tree-right-side-view/
//same as level order of Binary tree only twist is that we need to capture last element of each level. Thats it......
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        vector<int> result;
        vector<int> elementsByLevel;
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            int len=q.size();
            while(len--){
                temp=q.front();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                q.pop();
            }
            result.push_back(temp->val);
        }
        return result;
    }
};
