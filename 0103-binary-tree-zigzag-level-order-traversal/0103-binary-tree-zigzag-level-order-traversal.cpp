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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root == NULL) return result;


        queue<TreeNode*>que;
        que.push(root);

        bool leftToRight=true;

        while(!que.empty()){
            int size=que.size();
            vector<int>level(size);

            for(int i=0;i<size;i++){
                TreeNode* node = que.front();
                que.pop();

                int idx=(leftToRight==true)?(i):(size-i-1);
                level[idx]=node->val;

                if(node->left){
                    que.push(node->left);
                }
                if(node->right){
                    que.push(node->right);
                }
            }
            leftToRight=!leftToRight;
            result.push_back(level);
        }
        return result;
    }
};