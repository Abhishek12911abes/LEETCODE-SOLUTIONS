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
    // Brute wala Solve

    // int solve(TreeNode* root){
    //     if(!root){
    //         return 0;
    //     }
    //     int leftH=solve(root->left);
    //     int rightH=solve(root->right);

    //     return max(leftH,rightH)+1;
    // }

    // Optimal wala solve
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftH=solve(root->left);
        if(leftH==-1){
            return -1;
        }

        int rightH=solve(root->right);

        if(rightH==-1){
            return -1;
        }

        if(abs(leftH-rightH)>1){
            return -1;
        }

        return max(leftH,rightH)+1;
    }
    bool isBalanced(TreeNode* root){
        //Approach 1) Brute TC O(n^2)
        // if(!root){
        //     return true;
        // }
        // int leftHeight=solve(root->left);
        // int rightHeight=solve(root->right);

        // if(abs(leftHeight-rightHeight)>1){
        //     return false;
        // }

        // return isBalanced(root->left) && isBalanced(root->right);

        if(!root){
            return true;
        }

        return solve(root)!=-1;
    }
};