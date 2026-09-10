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
    int findSum(TreeNode* root , int &count){
        if(root==NULL){
            return 0;
        }

        count++;

        int lSum=findSum(root->left,count);
        int rSum=findSum(root->right,count);

        return lSum+rSum+root->val;
    }
    int solve(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        int count=0;
        int res=0;

        int sum=findSum(root,count);

        if(root->val==sum/count){
            res++;
        }

        res+=solve(root->left);
        res+=solve(root->right);

        return res;

    }
    int averageOfSubtree(TreeNode* root) {
        return solve(root);
        
    }
};