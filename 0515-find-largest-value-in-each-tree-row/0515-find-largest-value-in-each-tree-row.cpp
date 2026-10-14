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
    vector<int>solve(TreeNode* root){
        vector<int>ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            int maxi=INT_MIN;
            for(int i=0;i<size;i++){
                TreeNode* temp=que.front();
                que.pop();

                maxi = max(maxi, temp->val);

                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            ans.push_back(maxi);
        }

        return ans;
    }
    vector<int> largestValues(TreeNode* root) {
        return solve(root);
    }
};