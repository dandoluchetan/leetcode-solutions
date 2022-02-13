class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return {};
        
        queue<TreeNode*> q;
        vector<int> elementsInLevel;
        vector<vector<int>> result;
        TreeNode* temp;
        q.push(root);
        temp=root;
        while(!q.empty()){
            int qSize=q.size();
            for(int i=0;i<qSize;i++){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                elementsInLevel.push_back(q.front()->val);
                q.pop();
                temp=q.front();
            }
            result.insert(result.begin(),elementsInLevel);
            elementsInLevel.clear();
        }
        return result;
    }
};
