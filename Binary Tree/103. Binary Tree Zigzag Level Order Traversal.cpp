class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> result;
        vector<int> elementsInLevel;
        queue<TreeNode*> q; 
        TreeNode* temp;
        bool directionOpposite=false;
        q.push(root);
        temp=root;
        
        while(!q.empty()){
            int qLen=q.size();
            for(int i=0;i<qLen;i++){
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                if(directionOpposite){
                    elementsInLevel.insert(elementsInLevel.begin(),temp->val);
                    q.pop();
                    temp=q.front();
                    continue;
                }
                elementsInLevel.push_back(temp->val);
                q.pop();
                temp=q.front();
            } 
            result.push_back(elementsInLevel);
            elementsInLevel.clear();
            (directionOpposite)?(directionOpposite=false):(directionOpposite=true);
        }
        return result;
    }
};
