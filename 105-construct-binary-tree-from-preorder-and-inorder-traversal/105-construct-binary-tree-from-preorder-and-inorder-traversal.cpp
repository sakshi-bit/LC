/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &idx,int left,int right){
        if(left>right)
            return NULL;
        
        
        int pivot = left;
        while(inorder[pivot]!=preorder[idx])
            pivot++;
        
        
        idx++;
        
        TreeNode* newnode = new TreeNode(inorder[pivot]);
        newnode->left = solve(preorder,inorder,idx,left,pivot-1);
        newnode->right = solve(preorder,inorder,idx,pivot+1,right);
        return newnode;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        int idx = 0;
        return solve(preorder,inorder,idx,0,n-1);
        
    }
};