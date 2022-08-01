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
    int f(TreeNode* root, int k, bool isleft){
        if(root)
            if(isleft)
                return max(f(root->left,1,true),f(root->right,k+1,false));
            else
                return max(f(root->left,k+1,true),f(root->right,1,false));
        return k-1;
    }
    int longestZigZag(TreeNode* root) {
        return f(root,0,true);
    }
};