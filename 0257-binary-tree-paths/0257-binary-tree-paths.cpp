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
    void Path(TreeNode* root,string v,vector<string>&res)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL)
        {
            v+=to_string(root->val);
            res.push_back(v);
            return;
        }

         v+=to_string(root->val)+"->";

        if(root->left)
        {
        Path(root->left,v,res);
        }

        if(root->right)
        {
        Path(root->right,v,res);
        }
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string>res;
        string v;

        Path(root,v,res);


        return res;
    }
};