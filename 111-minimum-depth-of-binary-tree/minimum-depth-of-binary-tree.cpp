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
    int find(TreeNode*root){
        if(root==NULL)
        return 1000000;
        if(root->left==NULL && root->right==NULL)
        return 1;
        int l=find(root->left);
        int r=find(root->right);
        return 1+min(l,r);
    }
    int minDepth(TreeNode* root) {
       int ans= find(root);
       if(ans>=1000000)
       return 0;
       return ans;
    }
};