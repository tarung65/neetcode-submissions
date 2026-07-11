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
    int maxSumPathdfs(TreeNode* root,int& res){
        if(!root){
            return 0;
        }

        int leftMax = max(maxSumPathdfs(root->left,res),0);
        int rightMax = max(maxSumPathdfs(root->right,res),0);
        res = max(res,root->val+leftMax+rightMax);
        return root->val + max(leftMax, rightMax);
        
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = root->val;
        maxSumPathdfs(root,res);
        return res;
    }
};
