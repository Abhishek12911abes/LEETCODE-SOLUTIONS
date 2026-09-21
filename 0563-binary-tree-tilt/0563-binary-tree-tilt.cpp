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
    int sum=0;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int lSum=solve(root->left);
        int rSum=solve(root->right);

        int absDiff=abs(lSum-rSum);
        sum+=absDiff;

        return lSum+rSum+root->val;

    }
    int findTilt(TreeNode* root) {
        solve(root);
        return sum;
    }
};