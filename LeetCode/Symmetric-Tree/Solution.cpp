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
    bool mirror(TreeNode* leftsub,TreeNode* rightsub)
    {
        if(leftsub==NULL && rightsub==NULL)
        {
            return true;
        }

        if(leftsub==NULL || rightsub==NULL)
        {
            return false;
        }

        return (leftsub->val==rightsub->val) && mirror(leftsub->left,rightsub->right)
        && mirror(leftsub->right,rightsub->left);


    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }

        return mirror(root->left,root->right);
    }
};