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
    int solve(TreeNode* root,int& mxsum)
    {
        if(root==NULL) return 0;
        int lsum=solve(root->left,mxsum);
        int rsum=solve(root->right,mxsum);

        int tmp=root->val+max(lsum>0?lsum:0,rsum>0?rsum:0);
        int ans=max({tmp,lsum+rsum+root->val,root->val});
        mxsum=max(mxsum,ans);

        return tmp;
    }
    int maxPathSum(TreeNode* root) {

        int mxsum=INT_MIN;
        solve(root,mxsum);


        return mxsum;
    }
};