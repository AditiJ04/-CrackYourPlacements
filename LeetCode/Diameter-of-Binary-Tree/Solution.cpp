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
    int solve(TreeNode* root, int& res) {
        if (root == NULL) return 0;

        int l = solve(root->left, res);
        int r = solve(root->right, res);

        // Update the result with the number of edges in the longest path through root
        res = max(res, l + r);

        // Return height of the subtree
        return 1 + max(l, r);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root, res);
        return res; // number of edges, no need to subtract 1 anymore
    }
};
