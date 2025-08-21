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

   bool ValidateBST(TreeNode* root, long long mini, long long maxi) {
    if (!root) return true;
    if (root->val <= mini || root->val >= maxi) return false;
    return ValidateBST(root->left, mini, root->val) &&
           ValidateBST(root->right, root->val, maxi);
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;

        if(root->left==NULL && root->right==NULL) return true;

        return ValidateBST(root,LLONG_MIN,LLONG_MAX);
    }
};