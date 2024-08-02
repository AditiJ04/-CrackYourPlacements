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

        int lev=1;
        que.push(root);
        que.push(NULL);
        vector<int>v;

        while(!que.empty())
        {
            
            TreeNode* fro=que.front();
            que.pop();


            if(fro==NULL)
            {
                lev++;

                if(lev%2!=0)
                {
                    reverse(v.begin(),v.end());
                }
                 ans.push_back(v);

                v.clear();

                if(que.size()>0)
                {
                    que.push(NULL);
                }
            }

            else
            {
            v.push_back(fro->val);
            if(fro->left)
            {
                que.push(fro->left);
            }

            if(fro->right)
            {
                que.push(fro->right);
            }

            }
        }

        return ans;
    }
};