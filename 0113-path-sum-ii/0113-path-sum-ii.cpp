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
    vector<vector<int>>ans;
    void solve(TreeNode* root , int targetSum , vector<int>& res , vector<vector<int>>& ans){
        // 4 , 17
        // 11 , 13
        // 7 , 2
        if(!root){
            return;
        }

        res.push_back(root->val);
        
        if(!root->left && !root->right){
            if(targetSum-root->val==0){
                ans.push_back(res);
            }
        }

        solve(root->left,targetSum-root->val,res,ans);
       
        solve(root->right,targetSum-root->val,res,ans);

        res.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        if(!root){
            return ans;
        }
        vector<int>res;
        solve(root,targetSum,res,ans);
        return ans;
    }
};