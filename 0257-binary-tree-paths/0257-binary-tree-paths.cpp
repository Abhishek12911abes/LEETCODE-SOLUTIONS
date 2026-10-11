class Solution {
public:
    void solve(TreeNode* root, string path, vector<string>& res) {
        if (!root) {
            return;
        }

        path += to_string(root->val);

        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }

        path += "->";

        if (root->left) {
            solve(root->left, path, res);
        }

        if (root->right) {
            solve(root->right, path, res);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        solve(root, "", result);
        return result;
    }
};