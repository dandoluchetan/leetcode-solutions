class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(inorder.size()==0)
            return NULL;
        TreeNode* root=new TreeNode(preorder[0]);
        int position=find(inorder.begin(),inorder.end(),preorder[0])-inorder.begin();
        cout<<position<<endl;
        preorder.erase(preorder.begin());
        vector<int> leftTreeInorder(inorder.begin(),inorder.begin()+position);
        vector<int> rightTreeInorder(inorder.begin()+position+1,inorder.end());
        
        root->left=buildTree(preorder,leftTreeInorder);
        root->right=buildTree(preorder,rightTreeInorder);
        
        return root;
    }
};
