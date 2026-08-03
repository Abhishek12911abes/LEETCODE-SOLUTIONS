class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int i = 0;
        while (i < n) {
            unordered_set<int> st;

            for (int j = 0; j < n; j++) {
                st.insert(matrix[i][j]);
            }

            if (st.size() != n)
                return false;


            i++;
        }

        int j = 0;
        while (j < n) {
            unordered_set<int> st;

            for (int i = 0; i < n; i++) {
                st.insert(matrix[i][j]);
            }

            if (st.size() != n)
                return false;

            j++;
        }

        return true;
    }
};