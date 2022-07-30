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
    bool symmetric(TreeNode* rl,TreeNode* rr ){
        if(!rl && !rr){
            return 1;
        }
        if(!rl || !rr || (rl->val != rr->val)){
            return 0;
        }
        
        return symmetric(rl->left,rr->right) && symmetric(rr->left,rl->right);
    }
    bool isSymmetric(TreeNode* root) {
       return  symmetric(root->left,root->right);
    }
};