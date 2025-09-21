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
    int px=-1,dx=-1;
    int py=-1,dy=-1;

    void findCousins(TreeNode* root,int x,int y,int lev,TreeNode* parRoot)
    {
        if(root==NULL) return;

        if(root->val==x)
        {
            px=parRoot->val;
            dx=lev;
            return;
        }

        if(root->val==y)
        {
            py=parRoot->val;
            dy=lev;
            return;
        }
  
        findCousins(root->left,x,y,lev+1,root);
        findCousins(root->right,x,y,lev+1,root);

    }
    bool isCousins(TreeNode* root, int x, int y) {
        findCousins(root,x,y,0,root);

        if(dx!=dy)
        {
            return false;
        }

        if(px!=py) return true;

        return false;
    }
};