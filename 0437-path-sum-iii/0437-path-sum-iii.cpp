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
    int solve(TreeNode* root , long long targetSum){
        if(!root){
            return 0;
        }

        int ways=0;

        if(targetSum-root->val==0){
           ways++;
        }

        ways+=solve(root->left,targetSum-root->val);
        ways+=solve(root->right,targetSum-root->val);

        return ways;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root){
            return 0;
        }

        int ans=solve(root,targetSum);

        ans+=pathSum(root->left,targetSum);
        ans+=pathSum(root->right,targetSum);

        return ans;
        
    }
};