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
    map<pair<TreeNode*,char>,int>m;
    int find(TreeNode*root,char d){
        if(root==NULL)
        return 0;
        if(m.find({root,d})!=m.end())
        return m[{root,d}];
        int ans=0;
        if(d=='L'){
            ans=1+find(root->right,'R');
        }
        else{
            ans=1+find(root->left,'L');
        }
        return m[{root,d}]=ans;
    }
    int longest(TreeNode*root){
        if(root==NULL)
        return 0;
        int val=max(find(root,'L'),find(root,'R'));
        return max({val-1,longest(root->left),longest(root->right)});
    }
    int longestZigZag(TreeNode* root) {
        m.clear();
        return longest(root);
    }
};