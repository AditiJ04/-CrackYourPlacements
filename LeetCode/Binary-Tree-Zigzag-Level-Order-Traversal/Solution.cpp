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
        vector<vector<int>>ans;

        if(root==NULL)
        {
            return ans;
        }

        queue<TreeNode*>que;

        que.push(root);
        int flg=0;
        while(!que.empty())
        {
            int sz=que.size();
            vector<int>v;
            while(sz--)
            {
                TreeNode* node=que.front();
                v.push_back(node->val);
                que.pop();

                if(node->left)
                {
                    que.push(node->left);
                }

                if(node->right)
                {
                    que.push(node->right);
                }
            }

            if(flg)
            {
                reverse(v.begin(),v.end());
            }

            ans.push_back(v);
            flg=!flg;
        }

        return ans;
    }
};