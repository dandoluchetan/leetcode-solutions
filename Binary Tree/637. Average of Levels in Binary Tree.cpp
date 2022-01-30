//https://leetcode.com/problems/average-of-levels-in-binary-tree/

class Solution {
public:
    void preorder(TreeNode* root,int& level,map<int,vector<double>>& averagesOfLevel){
        if(!root){
            --level;
            return;
        }
        averagesOfLevel[level].push_back(root->val);
        
        preorder(root->left,++level,averagesOfLevel);
        preorder(root->right,++level,averagesOfLevel);
        --level;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,vector<double>> averagesOfLevel;
        vector<double> average;
        int level=0;
        preorder(root,level,averagesOfLevel);
        
        for(int i=0;i<averagesOfLevel.size();i++){
            average.push_back(accumulate(averagesOfLevel[i].begin(),averagesOfLevel[i].end(),0.00)/averagesOfLevel[i].size());
        }
        
        return average;
    }
};
