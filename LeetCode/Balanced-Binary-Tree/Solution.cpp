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
14    int height(TreeNode* root)
15    {
16        if(root==NULL) return 0;
17
18        int lh=height(root->left);
19        int rh=height(root->right);
20
21        return 1+max(lh,rh);
22    }
23    bool isBalanced(TreeNode* root) {
24        if(root==NULL) return true;
25
26        bool l,h;
27        l=isBalanced(root->left);
28        h=isBalanced(root->right);
29
30        bool ans=abs(height(root->left)-height(root->right))<=1;
31
32        if(l && h && ans) return true;
33
34        return false;
35    }
36};