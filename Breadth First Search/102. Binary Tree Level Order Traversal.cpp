//https://leetcode.com/problems/binary-tree-level-order-traversal/
class Solution {
public:
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> elementsInLevel;
        vector<vector<int>> result;
        q.push(root);
        TreeNode* temp=root;
        if(!root)
            return {};
        while(!q.empty()){
            int lengthOfCurrentLevel=q.size();
            for(int i=0;i<lengthOfCurrentLevel;i++){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                elementsInLevel.push_back(q.front()->val);
                q.pop();
                if(!q.empty())
                    temp=q.front();
            }
            result.push_back(elementsInLevel);
            elementsInLevel.clear();
        }
        return result;
    }
};
