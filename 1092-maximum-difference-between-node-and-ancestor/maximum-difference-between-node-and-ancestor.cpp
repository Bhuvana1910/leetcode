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
    pair<int,int>find(TreeNode*root){
       if(root == NULL)
            return {INT_MAX, INT_MIN};
        pair<int,int> l = find(root->left);
        pair<int,int> r = find(root->right);
        int a = root->val;
        int b = root->val;
        if(l.first != INT_MAX) {
            a = min(a, l.first);
            b = max(b, l.second);
            ans = max(ans, abs(root->val - l.first));
            ans = max(ans, abs(root->val - l.second));
        }
        if(r.first != INT_MAX) {
            a = min(a, r.first);
            b = max(b, r.second);
            ans = max(ans, abs(root->val - r.first));
            ans = max(ans, abs(root->val - r.second));
        }
        return {a, b};
    }
    int maxAncestorDiff(TreeNode* root) {
       ans=INT_MIN;
       find(root);
       return ans; 
    }
};