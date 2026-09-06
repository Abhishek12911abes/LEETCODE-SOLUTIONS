class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& mp,
             int u,
             int parent,
             vector<bool>& vis) {
        
        vis[u] = true;

        for(int v : mp[u]) {
            if(v == parent)
                continue;

            if(vis[v])
                return true;

            if(dfs(mp, v, u, vis))
                return true;
        }

        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> mp;

        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);

            vector<bool> vis(n + 1, false);

            if(dfs(mp, u, -1, vis))
                return edge;
        }

        return {};
    }
};