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

    int mx=INT_MIN;

    int maxPath(TreeNode* root)
    {
        if(root==NULL) return 0;

        int lpath=maxPath(root->left);
        int rpath=maxPath(root->right);

        int tmp=root->val+max(lpath>0?lpath:0,rpath>0?rpath:0);
        int ans=max({tmp,lpath+rpath+root->val,root->val});
        mx=max(mx,ans);

        return tmp;
    }
    int maxPathSum(TreeNode* root) {
        maxPath(root);

        return mx;
    }
};