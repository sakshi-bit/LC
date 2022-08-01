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
    TreeNode* helper(vector<int>&inorder, vector<int>& postorder, int instart,int inend,int poststart,int postend){
        if(instart>inend){
            return NULL;
        }
        
        int rootval = postorder[postend];
        TreeNode* root = new TreeNode(rootval);
        int rootindex = instart;
        
        for(;rootindex<=inend;rootindex++){
            if(inorder[rootindex]==rootval){
                break;
            }
        }
        
        int leftsize = rootindex-instart;
        int rightside = inend-rootindex;
        
        root->left = helper(inorder,postorder,instart,rootindex-1,poststart,poststart+leftsize-1);
        root->right = helper(inorder,postorder,rootindex+1,inend,postend-rightside,postend-1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        return helper(inorder,postorder,0,len-1,0,len-1);
    }
};