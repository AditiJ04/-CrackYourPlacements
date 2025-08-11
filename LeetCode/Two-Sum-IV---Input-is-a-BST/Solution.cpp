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

    bool findSum(TreeNode* root,int k)
    {
        if(root==NULL) return true;

        if(mp.find(k-root->val)!=mp.end()) return true;
        
        mp[root->val]++;

        if(root->left)
        {
          if(findSum(root->left,k)) return true;
        }

        if(root->right)
        {
          if(findSum(root->right,k)) return true;
        }

        return false;
    }
    bool findTarget(TreeNode* root, int k) {
       return findSum(root,k);
    }
};