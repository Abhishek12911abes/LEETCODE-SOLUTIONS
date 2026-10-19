class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;

    void mapping(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            mp[root->left] = root;
        }

        mapping(root->left);

        if (root->right) {
            mp[root->right] = root;
        }

        mapping(root->right);
    }

    TreeNode* findNode(TreeNode* root, int start) {
        if (!root) return nullptr;

        if (root->val == start) return root;

        TreeNode* left = findNode(root->left, start);
        if (left) return left;

        return findNode(root->right, start);
    }

    int solve(TreeNode* node) {
        queue<TreeNode*> que;
        unordered_set<TreeNode*> st;

        que.push(node);
        st.insert(node);

        int count = -1;

        while (!que.empty()) {
            int n = que.size();
            count++;

            while (n--) {
                TreeNode* temp = que.front();
                que.pop();

                if (temp->left && !st.count(temp->left)) {
                    que.push(temp->left);
                    st.insert(temp->left);
                }

                if (temp->right && !st.count(temp->right)) {
                    que.push(temp->right);
                    st.insert(temp->right);
                }

                if (mp.count(temp) && !st.count(mp[temp])) {
                    que.push(mp[temp]);
                    st.insert(mp[temp]);
                }
            }
        }

        return count;
    }

    int amountOfTime(TreeNode* root, int start) {
        mapping(root);

        TreeNode* node = findNode(root, start);

        return solve(node);
    }
};