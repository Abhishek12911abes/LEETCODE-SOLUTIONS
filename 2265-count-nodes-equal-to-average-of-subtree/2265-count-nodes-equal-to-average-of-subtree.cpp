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
    // int findSum(TreeNode* root , int &count){
    //     if(root==NULL){
    //         return 0;
    //     }

    //     count++;

    //     int lSum=findSum(root->left,count);
    //     int rSum=findSum(root->right,count);

    //     return lSum+rSum+root->val;
    // }
    // int solve(TreeNode* root){
    //     if(root==NULL){
    //         return 0;
    //     }
    //     int count=0;
    //     int res=0;

    //     int sum=findSum(root,count);

    //     if(root->val==sum/count){
    //         res++;
    //     }

    //     res+=solve(root->left);
    //     res+=solve(root->right);

    //     return res;

    // }
    int result;
    pair<int,int> solve(TreeNode* root){
        if(root==NULL){
            return {0,0};
        }
        auto p1=solve(root->left);
        auto p2=solve(root->right);

        int totalSum=p1.first+p2.first+root->val;

        int totalNodes=p1.second+p2.second+1;

        if((totalSum/totalNodes)==root->val){
            result+=1;
        }

        return {totalSum,totalNodes};

    }
    int averageOfSubtree(TreeNode* root) {
        // Approach 1) Brute Force

        // return solve(root);

        // Approach 2) Optimal

        result=0;
        solve(root);

        return result;
        
    }
};