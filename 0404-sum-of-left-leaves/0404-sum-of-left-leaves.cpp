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
    void Sum(TreeNode* root,int &sum,int &flg)
    {

        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL && root->right==NULL && flg==0)
        {
            sum+=root->val;
            return;
        }
        if(root->left)
        {
        flg=0;
        Sum(root->left,sum,flg);
        }

        if(root->right)
        {
        flg=1;
        Sum(root->right,sum,flg);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {

        int sum=0;
        int flg=0;

        if(root->left==NULL && root->right==NULL)
        {
            return 0;
        }
        Sum(root,sum,flg);

        return sum;
    }
};