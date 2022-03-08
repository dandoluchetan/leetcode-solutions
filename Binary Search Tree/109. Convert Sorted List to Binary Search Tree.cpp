//https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
class Solution {
public:
    TreeNode* buildBST(vector<int> sortedList){
        if(sortedList.size()==1)
            return new TreeNode(sortedList[0]);
        if(sortedList.size()==0)
            return NULL;
        
        int mid=sortedList.size()/2;
        cout<<sortedList.size()<<endl;
        TreeNode* root=new TreeNode(sortedList[mid]);
        
        vector<int> leftSortedList(sortedList.begin(),sortedList.begin()+mid);
        vector<int> rightSortedList(sortedList.begin()+mid+1,sortedList.end());
        
        root->left=buildBST(leftSortedList);
        root->right=buildBST(rightSortedList);
        
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
            return NULL;
        }
        vector<int> sortedList;
        ListNode* head1;
        head1=head;
        while(head1){
            sortedList.push_back(head1->val);
            head1=head1->next;
        }
        cout<<sortedList.size()<<endl;
        return buildBST(sortedList);                     
    }
};
