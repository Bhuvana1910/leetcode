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
int find(TreeNode* root, int start){
    if(root==NULL)
    return 0;
    int l=find(root->left,start);
    int r=find(root->right,start);
    if(root->val==start){
    ans=max({ans,l,r});
    return -1;
    }
    if(l<0 ||r<0){
        ans=max({ans,abs(r)+abs(l)});
        if(l<0)
        return l-1;
        return r-1;
    }
    return 1+max(l,r);

}
    int amountOfTime(TreeNode* root, int start) {
        ans=0;
        find(root,start);
        return ans;
    }
};