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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int ps,int pe,int is,int ie,unordered_map<int,int>&mpp){
        if(ps>pe || is>ie){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[ps]);
        int rootidx = mpp[root->val];
        int left = rootidx-is;
        //reccursive calls
        root->left = solve(preorder,inorder,ps+1,ps+left,is,rootidx-1,mpp);
        root->right = solve(preorder,inorder,ps+left+1,pe,rootidx+1,ie,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int m = inorder.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<m;i++){
            mpp[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,n-1,0,m-1,mpp);
    }
};