class Solution {
public:
    void solve(TreeNode* root, bool flag){
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            vector<TreeNode*> nodes;

            while(size--){
                TreeNode* node = que.front();
                que.pop();

                nodes.push_back(node);

                if(node->left){
                    que.push(node->left);
                }

                if(node->right){
                    que.push(node->right);
                }
            }

            if(flag){
                int i = 0;
                int j = nodes.size() - 1;

                while(i < j){
                    swap(nodes[i]->val, nodes[j]->val);
                    i++;
                    j--;
                }
            }

            flag = !flag;
        }
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root){
            return NULL;
        }

        bool flag = false;
        solve(root, flag);

        return root;
    }
};