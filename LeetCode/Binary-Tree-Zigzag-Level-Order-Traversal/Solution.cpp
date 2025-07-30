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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        if(root==NULL) return {};

        map<int,vector<int>>mp;
        vector<vector<int>>ans;

        queue<pair<TreeNode*,int>>que;

        que.push({root,0});

        while(!que.empty())
        {
            TreeNode* node=que.front().first;
            int dep=que.front().second;

            mp[dep].push_back(node->val);
            que.pop();

            if(node->left) que.push({node->left,dep+1});
            if(node->right) que.push({node->right,dep+1});
        }

        int flg=0;
        for(auto it:mp)
        {
            if(flg) reverse(it.second.begin(),it.second.end());
            ans.push_back(it.second);
            flg=!flg;
        }
        return ans;
    }
};