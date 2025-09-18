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

    unordered_map<int,vector<int>>mp;
    
    void findTraversal(TreeNode* root,int lev)
    {
        if(root==NULL)
        {
            return;
        }
        
        mp[lev].push_back(root->val);
        findTraversal(root->left,lev+1);
        findTraversal(root->right,lev+1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL) return {};
        findTraversal(root,0);
        int lev=mp.size()-1;
        
        vector<vector<int>>res;
        
        while(lev>=0)
        {
            res.push_back(mp[lev]);
            lev--;
        }
        
        return res;
    }
};