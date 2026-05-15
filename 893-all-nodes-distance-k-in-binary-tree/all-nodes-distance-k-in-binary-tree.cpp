/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<TreeNode*,TreeNode*>m;
    void find(TreeNode* root){
        if(root==NULL)
        return;
        if(root->left)
        m[root->left]=root;
        find(root->left);
        if(root->right)
        m[root->right]=root;
        find(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        m.clear();
        find(root);
        set<TreeNode*>s;
        int l=0;
        vector<int>temp;
        deque<TreeNode*>q;
        s.insert(target);
        q.push_back(target);
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode*c=q.front();
                q.pop_front();
                if(l==k)
                temp.push_back(c->val);
                if(c->left && !s.count(c->left)){
                q.push_back(c->left);
                s.insert(c->left);
                }
                if(c->right && !s.count(c->right)){
                q.push_back(c->right);
                s.insert(c->right);
                }
                if(m[c] && !s.count(m[c])){
                q.push_back(m[c]);
                s.insert(m[c]);
                }
            }
            l++;
        }
        return temp;

    }
};