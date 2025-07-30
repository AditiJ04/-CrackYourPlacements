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
        	vector<vector<int>>res;
    	
    	if(root==NULL)
    	{
    	    return res;
    	}
    	queue<TreeNode*>que;
    	
    	que.push(root);
    	
    	bool LtoR=true;
    	
    	while(!que.empty())
    	{
    	    int s=que.size();
    	    vector<int>tmp(s);
    	    
    	    for(int i=0;i<s;i++)
    	    {
    	        TreeNode* fro=que.front();
    	        que.pop();
    	        
    	        int idx=LtoR?i:s-i-1;
    	        
    	        tmp[idx]=fro->val;
    	       
    	        if(fro->left)
    	        {
    	            que.push(fro->left);
    	        }
    	        
    	        if(fro->right)
    	        {
    	            que.push(fro->right);
    	        }
    	        
    	        
    	    }
    	     LtoR=!LtoR;
    	        
    	    
    	    res.push_back(tmp);
    	}
    	
    	return res;
    }
};