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
    int sumOfBinaryNumbers(TreeNode* root,int sum){
        if(!root){
            return 0;
        }
        int ans;
        if(root)
            ans = (2*sum)+root->val;
        
        if(!root->left && !root->right)
            return ans;
        
            return sumOfBinaryNumbers(root->left,ans)+sumOfBinaryNumbers(root->right,ans);
        
        return 0;
    }
    int sumRootToLeaf(TreeNode* root) {
        return sumOfBinaryNumbers(root,0);
    }
};