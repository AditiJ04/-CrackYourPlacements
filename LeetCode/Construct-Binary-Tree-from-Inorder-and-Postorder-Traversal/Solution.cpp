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

    unordered_map<int,int>mp;
    TreeNode* solve(vector<int>&inorder,vector<int>&postorder,int s,int e,int &idx)
    {
        if(s>e) return NULL;

        int currnum=postorder[idx];

        int i=mp[currnum];

        TreeNode* root=new TreeNode(currnum);

        idx--;
        root->right=solve(inorder,postorder,i+1,e,idx);
        root->left=solve(inorder,postorder,s,i-1,idx);
    
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();

        int idx=n-1;

        for(int i=0;i<n;i++)
        {
            mp[inorder[i]]=i;
        }

        return solve(inorder,postorder,0,n-1,idx);
    }
};