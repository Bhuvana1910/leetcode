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
    int ans;
    void find(TreeNode*root,string &s){
        if(root==NULL)
        return;
        s.push_back(root->val+'0');
        find(root->left,s);
        find(root->right,s);
        if(root->left==NULL && root->right==NULL)
        ans+=stoi(s);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
      string s;
      ans=0;
      find(root,s);
      return ans;  
    }
};