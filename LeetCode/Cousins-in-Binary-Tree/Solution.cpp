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
    int px=-1,py=-1;
    int dx=-1,dy=-1;

    bool isCousins(TreeNode* root, int x, int y) {
        if(root==NULL) return false;

        queue<pair<TreeNode*,TreeNode*>>que;

        que.push({root,root});
        int lev=0;

        while(!que.empty())
        {
            int sz=que.size();
            for(int i=0;i<sz;i++)
            {
                auto it=que.front().first;
                auto par=que.front().second;

                que.pop();
                if(it->val==x) 
                {
                    px=par->val;
                    dx=lev;
                }

                if(it->val==y) 
                {
                    py=par->val;
                    dy=lev;
                }
                if(px!=-1 && py!=-1)
                {
                    if(dx!=dy || px==py) return false;
                    return true;
                }

                if(it->left) que.push({it->left,it});
                if(it->right) que.push({it->right,it});
            }
            lev++;
        }

        return true;
    }
};