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
    int ans = INT_MIN;

    int solve(TreeNode* root, const int &maxSum){
        if(!root){
            return 0;
        }

        int take = 0, skip = 0;

        take = max(0, solve(root->left, maxSum));
        skip = max(0, solve(root->right, maxSum));

        ans = max(ans, root->val + take + skip);

        return root->val + max(take, skip);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return ans;
    }
};