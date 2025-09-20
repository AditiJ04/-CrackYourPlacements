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
    unordered_map<int, int> mp;

TreeNode* constructTree(vector<int>& postorder, int start_idx, int end_idx, int &post) {
    if (start_idx > end_idx) {
        return NULL;
    }

    // Get the current value from the postorder array and decrement the post index
    int val = postorder[post--];
    int idx = mp[val];

    // Create the root node for the current subtree
    TreeNode* root = new TreeNode(val);

    // Recursively build the right subtree first, since we're traversing postorder
    root->right = constructTree(postorder, idx + 1, end_idx, post);
    
    // Recursively build the left subtree
    root->left = constructTree(postorder, start_idx, idx - 1, post);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();

    // Map each value in the inorder traversal to its index
    for (int i = 0; i < n; i++) {
        mp[inorder[i]] = i;
    }

    // Start with the last index of postorder (the root of the tree)
    int post = n - 1;

    // Construct the binary tree
    return constructTree(postorder, 0, n - 1, post);
}
};