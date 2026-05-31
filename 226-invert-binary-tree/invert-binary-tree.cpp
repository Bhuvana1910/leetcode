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
    TreeNode* find(TreeNode* root){
        if(root==NULL)
        return NULL;
        TreeNode* ol=root->left;
        TreeNode* r=root->right;
        root->left=find(r);
        root->right=find(ol);
        return root;

    }
    TreeNode* invertTree(TreeNode* root) {
        return find(root);
    }
};