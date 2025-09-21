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
    TreeNode* pX=NULL;
    TreeNode* pY=NULL;
    int xl=-1;
    int yl=-1;
    void findCousin(TreeNode* root,int x,int y,TreeNode* nnode,int lev)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->val==x)
        {
            pX=nnode;
            xl=lev;
            return;
        }

        if(root->val==y)
        {
            pY=nnode;
            yl=lev;
            return;
        }

        findCousin(root->left,x,y,root,lev+1);
        findCousin(root->right,x,y,root,lev+1);
    }
    bool isCousins(TreeNode* root, int x, int y) {

     //   TreeNode* nnode=new TreeNode(-1);
        if(root==NULL)
        {
            return false;
        }
        findCousin(root,x,y,NULL,0);
     //   findCousin(root,y,nnode);

        if(xl==yl && pX!=pY)
        {
            return true;
        }

        return false;
    }
};