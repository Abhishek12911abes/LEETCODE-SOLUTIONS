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
    int solve(TreeNode* root){
        queue<pair<TreeNode* , int>>que;
        que.push({root,1});
        int maxSum=INT_MIN;
        int maxLevel=INT_MIN;
        while(!que.empty()){
            int sum=0;
            int size=que.size();
            int level;
            for(int i=0;i<size;i++){
                auto temp=que.front();
                que.pop();

                TreeNode* node=temp.first;
                level=temp.second;

                sum+=node->val;

                if(node->left){
                    que.push({node->left,level+1});
                }
                if(node->right){
                    que.push({node->right,level+1});
                }
            }
            if(sum>maxSum){
                maxSum=sum;
                maxLevel=level;
            }
        }
        return maxLevel;
    }
    int maxLevelSum(TreeNode* root) {
        return solve(root);
        
    }
};