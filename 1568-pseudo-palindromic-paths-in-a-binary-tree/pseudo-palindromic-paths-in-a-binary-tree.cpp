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
    map<int,int>m;
    int ans;
    bool check(map<int,int>&m){
        int o=0;
        for(auto i:m){
            if(i.second%2==1)
            o++;

        }
        if(o<=1)
        return true;
        return false;
    }
    void find(TreeNode*root){
        if(root==NULL)
        return;
        if(root->right==NULL && root->left==NULL){
            m[root->val]++;
            if(check(m))
            ans++;
            m[root->val]--;
            return;
        }
        m[root->val]++;
        find(root->left);
        find(root->right);
        m[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        ans=0;
        find(root);
        return ans;
         
        
    }
};