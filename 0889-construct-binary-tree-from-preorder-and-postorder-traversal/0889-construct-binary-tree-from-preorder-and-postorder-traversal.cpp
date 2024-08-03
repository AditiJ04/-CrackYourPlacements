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
    int preidx=0,postidx=0;
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        TreeNode* root=new TreeNode(pre[preidx++]);
        if(root->val!=post[postidx])
        {
            root->left=constructFromPrePost(pre,post);
        }

         if(root->val!=post[postidx])
        {
            root->right=constructFromPrePost(pre,post);
        }
        postidx++;

        return root;
    }
};