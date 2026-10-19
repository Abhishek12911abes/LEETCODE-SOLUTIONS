/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode* , TreeNode*> mp;
    void mapping(TreeNode* root){
        if(!root){
            return ;
        }

        if(root->left!=NULL){
            mp[root->left]=root;
        }

        mapping(root->left);

        if(root->right!=NULL){
            mp[root->right]=root;
        }

        mapping(root->right);
    }

    void solve(TreeNode* target , int k,vector<int>& ans){

        queue<TreeNode*>que;
        que.push(target);

        unordered_set<TreeNode*> st;
        st.insert(target);

        while(!que.empty()){
            int n=que.size();

            if(k==0){
                break;
            }

            while(n--){
                TreeNode* temp=que.front();
                que.pop();

                if(temp->left && !st.count(temp->left)){
                    que.push(temp->left);
                    st.insert(temp->left);
                }
                if(temp->right && !st.count(temp->right)){
                    que.push(temp->right);
                    st.insert(temp->right);
                }
                if(mp.count(temp) && !st.count(mp[temp])){
                    que.push(mp[temp]);
                    st.insert(mp[temp]);
                }
            }
            k--;
        }

        while(!que.empty()){
            TreeNode* temp=que.front();
            que.pop();

            ans.push_back(temp->val);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>ans;
        mapping(root);
        solve(target,k,ans);
        return ans;
        
    }
};