/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root) {
        queue<pair<TreeNode*, int>> que;
        que.push({root, 0});
        int maxWidth = INT_MIN;
        while (!que.empty()) {
            int n = que.size();
            int leftIdx = que.front().second;
            int rightIdx = que.back().second;
            maxWidth = max(maxWidth, rightIdx - leftIdx + 1);
            for (int i = 0; i < n; i++) {
                auto temp = que.front();
                que.pop();

                TreeNode* node=temp.first;
                long long idx = temp.second;

                if(node->left){
                    que.push({node->left,idx*2+1});
                }
                if(node->right){
                    que.push({node->right,idx*2+2});
                }
            }
        }
        return maxWidth;
    }
    int widthOfBinaryTree(TreeNode* root) { return solve(root); }
};