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

        queue<TreeNode*>que;

        if(root==NULL)
        {
            return ans;
        }

        que.push(root);
        int rev=0;

        while(!que.empty())
        {
            int sz=que.size();

            vector<int>tmp;
            for(int i=0;i<sz;i++)
            {
                TreeNode* node=que.front();
                tmp.push_back(node->val);
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

            if(rev==1)
            {
                reverse(tmp.begin(),tmp.end());
            }
            rev=!rev;
            ans.push_back(tmp);
        }

        return ans;
    }
};