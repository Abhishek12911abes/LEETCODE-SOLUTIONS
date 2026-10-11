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
    void solve(TreeNode* root,vector<int>& leaf){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            leaf.push_back(root->val);
            return ;
        }
        solve(root->left,leaf);
        solve(root->right,leaf);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>leaf1,leaf2;
        solve(root1,leaf1);
        solve(root2,leaf2);

        return leaf1==leaf2;
    }
};