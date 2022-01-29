/*
You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.
The test cases are generated so that the answer fits in a 32-bits integer.

Example 1:
Input: root = [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

Example 2:
Input: root = [0]
Output: 0

Constraints:
The number of nodes in the tree is in the range [1, 1000].
Node.val is 0 or 1.
*/

class Solution {
public:
    int binaryToDecimal(stack<int> binary){
        int i=0;
        int result=0;
        while(!binary.empty()){
            cout<<binary.top()<<";";
            result=result+pow(2,i)*(binary.top());
            binary.pop();
            i++;
        }
        cout<<endl<<result<<endl<<endl;
        return result;
    }
    void preorder(TreeNode* root,int& sumOfPaths,stack<int>& pileOfNumbers){
        if(!root){
            pileOfNumbers.push(0);
            return;
        }
        pileOfNumbers.push(root->val);
        if(!root->left && !root->right){
            sumOfPaths+=binaryToDecimal(pileOfNumbers);
            return;
        }
        preorder(root->left,sumOfPaths,pileOfNumbers);
        pileOfNumbers.pop();
        preorder(root->right,sumOfPaths,pileOfNumbers);
        pileOfNumbers.pop();
    }
    int sumRootToLeaf(TreeNode* root) {
        int sumOfPaths=0;
        stack<int> pileOfNumbers;
        preorder(root,sumOfPaths,pileOfNumbers);
        return sumOfPaths;
    }
};
