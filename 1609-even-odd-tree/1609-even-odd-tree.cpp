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
    int height(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(height(root->left),height(root->right))+1;
    }
   
    bool check(TreeNode* root,int level){
        if(root==NULL){
            return true;
        }
        if(level%2==0){
        if(root->val%2==0)
            return false;
        if(predata[level]>=root->val)
            return false;
        predata[level] = root->val;
        }else{
            if(root->val%2==1)return false;
            if(predata[level]<=root->val)return false;
            predata[level]=root->val;
        }
        
        return check(root->left,level+1)&&check(root->right,level+1);
        
            
        }
    
    vector<int>predata;
    bool isEvenOddTree(TreeNode* root) {
        int ht = height(root);
        predata.reserve(ht);
        
        for(int i=1;i<ht;i=i+2){
            predata[i] = INT_MAX;
        }
        return check(root,0);
    }
};