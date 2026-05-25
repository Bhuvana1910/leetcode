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
    int ans,l;
    void find(TreeNode*root,int h){
        if(root==NULL)
        return;
        if(root->left==NULL && root->right==NULL)
        {
         if(h>l)
         {
            ans=root->val;
            l=h;
         }
        }
        find(root->left,h+1);
        find(root->right,h+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        ans=0;
        l=-1;
        find(root,0);
        return ans;
    }
};