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
    
    bool dfs(TreeNode* root,int min_limit,int max_limit){
        if(!root) return true;
        if(root->val <=min_limit || root->val >= max_limit ) return false;
        return dfs(root->left,min_limit,root->val) &&
                dfs(root->right,root->val,max_limit);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root,INT_MIN,INT_MAX);
    }
};
