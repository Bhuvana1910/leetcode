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
    TreeNode* find(TreeNode* root, int val, int depth,int d){
        if(root==NULL)
        return NULL;
        root->left=find(root->left,val,depth,d+1);
        root->right=find(root->right,val,depth,d+1);
        if(depth==1 && d==1)
        {
             TreeNode*n=new TreeNode(val);
             n->left=root;
             n->right=NULL;
             return n;
        }
        else if(d==depth-1){
         TreeNode*n=new TreeNode(val);
         TreeNode*n1=new TreeNode(val);
         n->left=root->left;
         n1->right=root->right;
         root->left=n;
         root->right=n1;
        }
        return root;

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return find(root,val,depth,1);
    }
};