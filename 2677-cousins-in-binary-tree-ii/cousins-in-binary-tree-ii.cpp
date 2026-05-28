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
    void find(TreeNode* root,TreeNode* parent, map<TreeNode*,int>&ps){
        if(root==NULL)
        return;
        ps[parent]+=root->val;
        find(root->left,root,ps);
        find(root->right,root,ps);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
      map<TreeNode*,int>ps;
      find(root,NULL,ps);
      deque<pair<TreeNode*,TreeNode*>>q;
      q.push_back({root,NULL});
      root->val=0;
      while(!q.empty()){
        int n=q.size();
        vector<pair<TreeNode*,TreeNode*>>temp;
        int ls=0;
        while(n--){
            pair<TreeNode*,TreeNode*>c=q.front();
            q.pop_front();
        
            if(c.first->left){
                ls+=c.first->left->val;
                q.push_back({c.first->left,c.first});
                temp.push_back({c.first->left,c.first});
            }
            if(c.first->right){
                ls+=c.first->right->val;
                
                q.push_back({c.first->right,c.first});
                temp.push_back({c.first->right,c.first});
            }
        }
        for(int i=0;i<temp.size();i++){
            pair<TreeNode*,TreeNode*>p=temp[i];
            p.first->val=ls-ps[p.second];
        }
      }
      return root;  
    }
};