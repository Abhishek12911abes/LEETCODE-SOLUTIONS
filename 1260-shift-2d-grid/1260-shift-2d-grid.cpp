class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();
        int size = n * m;

        k %= size;

        vector<int> a;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                a.push_back(grid[i][j]);
            }
        }

        vector<int> shift;
        for(int i = size - k; i < size; i++){
            shift.push_back(a[i]);
        }

        vector<int> rest;
        for(int i = 0; i < size - k; i++){
            rest.push_back(a[i]);
        }

        vector<vector<int>> final(n, vector<int>(m));

        int row = 0, col = 0;
vector<int> ans;

for(int x : shift) ans.push_back(x);
for(int x : rest) ans.push_back(x);

int idx = 0;
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        final[i][j] = ans[idx++];
    }
}

        return final;
    }
};