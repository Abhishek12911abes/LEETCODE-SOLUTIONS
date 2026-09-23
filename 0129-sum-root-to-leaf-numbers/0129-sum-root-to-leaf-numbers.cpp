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
    int solve(TreeNode* root , int currNo){
        if(root == NULL) return 0;

        currNo=currNo*10+root->val;

        if(root->left==NULL && root->right==NULL){
            return currNo;
        }

        int left=solve(root->left,currNo);
        int right=solve(root->right,currNo);

        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        int currNo=0;
        return solve(root,currNo);
    }
};