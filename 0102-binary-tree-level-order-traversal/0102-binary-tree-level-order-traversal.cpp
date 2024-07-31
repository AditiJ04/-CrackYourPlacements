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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;

        if(root==NULL)
        {
            return ans;
        }

        queue<TreeNode*>que;

        que.push(root);
        que.push(NULL);

        vector<int>v;

        while(!que.empty())
        {
            TreeNode* p=que.front();
            que.pop();

            if(p==NULL)
            {
                ans.push_back(v);
                v.clear();

                if(que.size()>0)
                {
                    que.push(NULL);
                }
            }
            else
            {
                v.push_back(p->val);
                if(p->left)
                {
                    que.push(p->left);
                }
                if(p->right)
                {
                    que.push(p->right);
            }
            }
       
        }
        return ans;
    }
};