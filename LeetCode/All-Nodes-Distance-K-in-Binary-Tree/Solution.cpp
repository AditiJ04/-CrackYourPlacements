/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,TreeNode*>mp;

    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }

        if(root->left)
        {
            mp[root->left]=root;
        }
        inorder(root->left);

        if(root->right)
        {
            mp[root->right]=root;
        }
        inorder(root->right);
    }

    vector<int> BFS(TreeNode* target,TreeNode* root,int k)
    {
        queue<TreeNode*>que;
        unordered_set<int>vis;

        que.push(target);

        vis.insert(target->val);
        while(!que.empty())
        {
            int n=que.size();

            if(k==0)
            {
                break;
            }
            while(n--)
            {
                TreeNode* node=que.front();

                que.pop();

                if(node->left && !vis.count(node->left->val))
                {
                    que.push(node->left);
                    vis.insert(node->left->val);
                }
                if(node->right && !vis.count(node->right->val))
                {
                    que.push(node->right);
                    vis.insert(node->right->val);
                }
                if(mp.find(node)!=mp.end() && !vis.count(mp[node]->val))
                {
                    que.push(mp[node]);
                    vis.insert(mp[node]->val);
                }
            }

            k--;
        }

        vector<int>res;
        while(!que.empty())
        {
            res.push_back(que.front()->val);
            que.pop();
        }

        return res;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;

        //to store the parent
        inorder(root);

        return BFS(target,root,k);
    }
};