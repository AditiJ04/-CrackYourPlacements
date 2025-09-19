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
    TreeNode* createBST(vector<int>&nums,int l,int h)
    {
        int s=l,e=h;
        TreeNode* node=NULL;
        if(s<=e)
        { 
            int mid=(s+e)/2;
            node=new TreeNode(nums[mid]);
            node->left=createBST(nums,s,mid-1);
            node->right=createBST(nums,mid+1,e);
        }

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();

        int l=0;
        int h=n-1;
        int mid=(l+h)/2;

        TreeNode* nnode=new TreeNode(nums[mid]);
        nnode->left=createBST(nums,l,mid-1);
        nnode->right=createBST(nums,mid+1,h);

        return nnode;
    }
};