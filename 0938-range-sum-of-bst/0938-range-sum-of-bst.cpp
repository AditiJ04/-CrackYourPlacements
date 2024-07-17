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
    void Sum(TreeNode* root,int l,int h,int &sum)
    {
        if(root==NULL)
        {
            return;
        }
        if(l<=root->val && root->val<=h)
        {
            sum+=root->val;
        }
        Sum(root->left,l,h,sum);
        Sum(root->right,l,h,sum);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        int sum=0;

        Sum(root,low,high,sum);

        return sum;
    }
};