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
    TreeNode*find(map<int,int>&l,map<int,int>&r,int v){
        if(v==-1)
        return NULL;
        TreeNode*root=new TreeNode(v);
        int lf=-1,rf=-1;
        if(l.find(v)!=l.end())
        lf=l[v];
        if(r.find(v)!=r.end())
        rf=r[v];
        root->left=find(l,r,lf);
        root->right=find(l,r,rf);
        return root;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
      map<int,int>l,r;
      set<int>s;
      for(int i=0;i<descriptions.size();i++){
        if(descriptions[i][2]==0){
            r[descriptions[i][0]]=descriptions[i][1];
            s.insert(descriptions[i][1]);
        }
        else{
            l[descriptions[i][0]]=descriptions[i][1];
            s.insert(descriptions[i][1]);
        }

      }
      int v;
      for(int i=0;i<descriptions.size();i++){
        if(s.find(descriptions[i][0])==s.end())
        v=descriptions[i][0];
      }
      return find(l,r,v);
    }
};