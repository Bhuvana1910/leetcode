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
    int maxLevelSum(TreeNode* root) {
        int l=1,ans=root->val,k=1;
        deque<TreeNode*>q;
        q.push_back(root);
        while(!q.empty()){
            int n=q.size();
            int s=0;
            while(n--){
                TreeNode*f=q.front();
                s+=f->val;
                q.pop_front();
                if(f->left)
                q.push_back(f->left);
                if(f->right)
                q.push_back(f->right);
            }
            if(s>ans)
            {
                ans=s;
                l=k;
            }
            k++;
            
        }
        return l;
    }
};