//https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return NULL;
        cout<<*(postorder.end()-1)<<endl;
        TreeNode* root=new TreeNode(*(postorder.end()-1));
        int position=find(inorder.begin(),inorder.end(),*(postorder.end()-1))-inorder.begin();
        postorder.erase(postorder.end()-1);
        
        vector<int> leftInorder(inorder.begin(),inorder.begin()+position);
        vector<int> rightInorder(inorder.begin()+position+1,inorder.end());
        
        
        root->right=buildTree(rightInorder,postorder);
        root->left=buildTree(leftInorder,postorder);
        
        return root;
        
    }
};
