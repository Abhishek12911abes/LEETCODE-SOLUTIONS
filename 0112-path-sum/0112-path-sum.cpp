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
    bool solve(TreeNode* root , int target){
        if(!root){
            return false;
        }

        if(root->left==NULL && root->right==NULL){
            return target-root->val==0;
        }

        int leftSum=solve(root->left,target-root->val);
        int rightSum=solve(root->right,target-root->val);

        return leftSum || rightSum;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root){
            return false;
        }
        return solve(root,targetSum);
    }
};