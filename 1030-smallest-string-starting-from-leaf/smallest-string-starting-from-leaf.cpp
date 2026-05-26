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
    string ans;
    void find(TreeNode*root,string &temp){
        if(root==NULL)
        return;
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val+'a');
            reverse(temp.begin(),temp.end());
            if(temp<ans)
            ans=temp;
            reverse(temp.begin(),temp.end());
            temp.pop_back();
            return;
        }
        temp.push_back(root->val+'a');
        find(root->left,temp);
        find(root->right,temp);
        temp.pop_back();
    }
    string smallestFromLeaf(TreeNode* root) {
        for(int i=0;i<=8500;i++)
        ans+='z';
        string temp;
        find(root,temp);
        return ans;

    }
};