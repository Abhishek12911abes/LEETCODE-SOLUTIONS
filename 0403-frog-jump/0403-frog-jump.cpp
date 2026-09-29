
class Solution {
public:
    int n;
    unordered_map<int, unordered_map<int, bool>> dp;

    bool solve(vector<int>& stones, int pos, int lastJump,
               unordered_set<int>& st) {

        if (pos == stones[n - 1]) {
            return true;
        }

        if (dp.count(pos) && dp[pos].count(lastJump)) {
            return dp[pos][lastJump];
        }

        for (int jump = lastJump - 1;
             jump <= lastJump + 1; jump++) {

            if (jump <= 0) continue;

            int nextPos = pos + jump;

            if (st.count(nextPos)) {
                if (solve(stones, nextPos, jump, st)) {
                    return dp[pos][lastJump] = true;
                }
            }
        }

        return dp[pos][lastJump] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        unordered_set<int> st(stones.begin(), stones.end());

        return solve(stones, 0, 0, st);
    }
};