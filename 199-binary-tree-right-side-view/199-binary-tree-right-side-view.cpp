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
    void recursion(TreeNode* root, int level, vector<int>&view){
        if(root==NULL){
            return;
        }
        if(view.size()==level){
            view.push_back(root->val);
        }
        recursion(root->right,level+1,view);
        recursion(root->left,level+1,view);
        
        
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>view;
        recursion(root,0,view);
        return view;
    }
};