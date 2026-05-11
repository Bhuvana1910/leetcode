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
    void find(TreeNode*root,vector<int>&t){
        if(root==NULL)
        return;
        if(root->left==NULL && root->right==NULL)
        t.push_back(root->val);
        
        find(root->left,t);
        find(root->right,t);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>t1,t2;
        find(root1,t1);
        find(root2,t2);
        if(t1==t2)
        return true;
        return false;
    }
};