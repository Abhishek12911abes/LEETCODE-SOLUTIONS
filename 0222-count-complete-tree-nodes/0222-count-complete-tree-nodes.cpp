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
    int leftHeight(TreeNode* root){
        int depth = 0;
        while (root) {
            depth++;
            root = root->left;
        }
        return depth;
    }
     int rightHeight(TreeNode* root){
        int depth = 0;
        while (root) {
            depth++;
            root = root->right;
        }
        return depth;
    }
    int countNodes(TreeNode* root) {
        if(!root){
            return 0;
        }
        int lh=leftHeight(root);
        int rh=rightHeight(root);

        // If left depth equals right depth, it's a perfect binary tree
        if (lh == rh) {
            // Number of nodes in a perfect binary tree of height h is 2^h - 1
            return (1 << lh) - 1;
        }

        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};