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
   int findidx(vector<int>& inorder, int ele) {
    int n = inorder.size();
    for (int i = 0; i < n; i++) {
        if (ele == inorder[i]) {
            return i;
        }
    }
    return -1; // This case should never occur if inputs are valid
}

TreeNode* constructTree(vector<int>& preorder, vector<int>& inorder, int start_idx, int end_idx, int& preorderIndex) {
    // Base case: If there are no elements to construct the tree
    if (start_idx > end_idx) {
        return nullptr;
    }

    // Pick the current node from preorder traversal
    int currentVal = preorder[preorderIndex];
    preorderIndex++; // Move to the next element in preorder for the next recursive call
    TreeNode* root = new TreeNode(currentVal);

    // If the node has no children
    if (start_idx == end_idx) {
        return root;
    }

    // Find the index of this node in the inorder traversal
    int inorderIndex = findidx(inorder, currentVal);

    // Recursively build the left and right subtrees
    root->left = constructTree(preorder, inorder, start_idx, inorderIndex - 1, preorderIndex);
    root->right = constructTree(preorder, inorder, inorderIndex + 1, end_idx, preorderIndex);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int n = preorder.size();
    int preorderIndex = 0; // Start from the first element in preorder
    return constructTree(preorder, inorder, 0, n - 1, preorderIndex);
}

};