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
    void find(vector<vector<int>>&graph,TreeNode*root){
        if(root==NULL)
        return;
        if(root->left){
        graph[root->left->val].push_back(root->val);
        graph[root->val].push_back(root->left->val);
        }

        find(graph,root->left);
        if(root->right){
        graph[root->right->val].push_back(root->val);
        graph[root->val].push_back(root->right->val);
        }
        find(graph,root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
       
        vector<vector<int>>graph(1000001);
        find(graph,root);
        deque<int>q;
        set<int>vis;
        q.push_back(start);
        vis.insert(start);
        int s=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                int t=q.front();
                q.pop_front();
                for(int i=0;i<graph[t].size();i++){
                    if(!vis.count(graph[t][i])){
                        q.push_back(graph[t][i]);
                        vis.insert(graph[t][i]);
                    }
                }
            }
            if(q.empty())
            return s;
            s++;

        }
        return s;
    }
};