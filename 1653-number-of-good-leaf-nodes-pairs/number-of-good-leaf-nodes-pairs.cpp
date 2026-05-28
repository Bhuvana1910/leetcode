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
    vector<int>find(TreeNode* root, int distance){
        if(root==NULL)
        return {};
        if(root->left==NULL && root->right==NULL){
            return {1};
        }
        vector<int>l=find(root->left,distance);
        vector<int>r=find(root->right,distance);
        int n=l.size(),k=0;
        vector<int>temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<r.size();j++){
              if(l[i]+r[j]<=distance)
              ans++;  
            }
        }
        for(int x : l) {
            temp.push_back(x + 1);
        }
        for(int x : r) {
            temp.push_back(x + 1);
        }
        return temp;
       
    }
    int countPairs(TreeNode* root, int distance) {
        ans=0;
        find(root,distance);
        return ans;
    }
};