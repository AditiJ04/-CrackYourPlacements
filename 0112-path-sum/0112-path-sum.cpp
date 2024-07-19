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
    void Sum(TreeNode* root,int targetSum,int &sum,int &flg)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left==NULL && root->right==NULL)
        {
            sum+=root->val;
            if(sum==targetSum)
            {
                flg=1;
            }
                return;
            
        }

        sum+=root->val;

        if(root->left)
        {
        Sum(root->left,targetSum,sum,flg);
        sum-=root->left->val;
        }

        if(root->right)
        {
        Sum(root->right,targetSum,sum,flg);
        sum-=root->right->val;
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum=0;
        int flg=0;
        Sum(root,targetSum,sum,flg);
        if(flg)
        {
            return true;
        }
        return false;
    }
};