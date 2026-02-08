1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14
15    int findHeight(TreeNode* root)
16    {
17        if(root==NULL) return 0;
18        int lh=findHeight(root->left);
19        int rh=findHeight(root->right);
20
21        return 1+max(lh,rh);
22    }
23    bool isBalanced(TreeNode* root) {
24        if(root==NULL) return true;
25        if(root->left==NULL && root->right==NULL) return true;
26
27        int lh=0,rh=0;
28        bool l=false,r=false;
29
30        l=isBalanced(root->left);
31        r=isBalanced(root->right);
32        if(root->left)
33        {
34            lh=findHeight(root->left);
35        }
36        if(root->right)
37        {
38            rh=findHeight(root->right);
39        }
40
41        if(abs(lh-rh)<=1 && l && r) return true;
42        return false;
43    }
44};