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
    TreeNode* f=NULL,*s=NULL,*prev=NULL;

    void Inorder(TreeNode* root)
    {
        if(root==NULL) return;
        Inorder(root->left);

        if(prev && prev->val>root->val)
        {
            if(!f) f=prev;
            s=root;
        }
        prev=root;
        Inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        Inorder(root);

        if(f && s) swap(f->val,s->val);
    }
};