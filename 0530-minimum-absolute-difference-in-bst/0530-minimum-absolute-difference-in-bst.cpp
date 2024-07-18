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
    void mindiff(TreeNode* root,int &next,int &minD)
    {
        if(root==NULL)
        {
            return;
        }
        mindiff(root->left,next,minD);
        minD=min(minD,abs(root->val-next));
        next=root->val;

        mindiff(root->right,next,minD);
    }
    int getMinimumDifference(TreeNode* root) {
        int minD=INT_MAX;
        int next=INT_MAX;

        mindiff(root,next,minD);

        return minD;
    }
};