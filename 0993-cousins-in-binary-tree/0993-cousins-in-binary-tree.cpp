class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;

    void mapping(TreeNode* root) {
        if (!root) {
            return;
        }

        if (root->left) {
            mp[root->left] = root;
        }
        mapping(root->left);

        if (root->right) {
            mp[root->right] = root;
        }
        mapping(root->right);
    }

    bool solve(TreeNode* root, int x, int y) {
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            int n = que.size();
            bool xFound = false, yFound = false;
            TreeNode* xNode = nullptr;
            TreeNode* yNode = nullptr;

            while (n--) {
                TreeNode* temp = que.front();
                que.pop();

                if (temp->val == x) {
                    xFound = true;
                    xNode = temp;
                }

                if (temp->val == y) {
                    yFound = true;
                    yNode = temp;
                }

                if (temp->left) {
                    que.push(temp->left);
                }

                if (temp->right) {
                    que.push(temp->right);
                }
            }

            if (xFound && yFound) {
                return mp[xNode] != mp[yNode];
            }

            if (xFound || yFound) {
                return false;
            }
        }

        return false;
    }

    bool isCousins(TreeNode* root, int x, int y) {
        mp.clear();
        mapping(root);
        return solve(root, x, y);
    }
};