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
    int minimumOperations(TreeNode* root) {
       int c=0;
       deque<TreeNode*>q;
       q.push_back(root);
       while(!q.empty()){
        int n=q.size();
        vector<int>t,s;
        map<int,int>m;
        int j=0;
        while(n--){
            TreeNode*c=q.front();
            q.pop_front();
            if(c->left)
            {
                q.push_back(c->left);
                t.push_back(c->left->val);
                s.push_back(c->left->val);
                m[c->left->val]=j;
                j++;
            }
            if(c->right)
            {
                q.push_back(c->right);
                t.push_back(c->right->val);
                s.push_back(c->right->val);
                m[c->right->val]=j;
                j++;
            }
        }
        sort(s.begin(),s.end());
        for(int i=0;i<t.size();i++){
            if(s[i]==t[i])
            continue;
            int si = m[s[i]];
            int val = t[i];
            swap(t[i], t[si]);
            m[val] = si;
            m[s[i]] = i;
            c++;
        }
       }
       return c;

    }
};