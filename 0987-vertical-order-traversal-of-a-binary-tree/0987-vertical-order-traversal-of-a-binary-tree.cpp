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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root){
            return ans;
        }
        queue<pair<TreeNode*,pair<int,int>>>que;

        map<int,map<int,multiset<int>>>mp; // multiset isliye liya hai kyuki wo duplicates ke saath data ko asc order me store krta hai

        que.push({root,{0,0}});

        while(!que.empty()){
            auto it=que.front();
            que.pop();

            TreeNode* node=it.first;

            int row=it.second.first;
            int col=it.second.second;

            mp[col][row].insert(node->val); // FIXED
            
            if(node->left){
                que.push({node->left,{row+1,col-1}});
            }
            if(node->right){
                que.push({node->right,{row+1,col+1}});
            }
        }

        for(auto col : mp){
            vector<int>res;
            for(auto row : col.second){
                for(int val : row.second){
                    res.push_back(val);
                }
            }
            ans.push_back(res);
        }
        return ans;


        
    }
};