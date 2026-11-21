class Solution {
public:
    int dp[366];

    int solve(vector<int>& days, vector<int>& costs, int day,
              int lastDay, unordered_set<int>& st) {

        if(day > lastDay) {
            return 0;
        }

        if(dp[day] != -1) {
            return dp[day];
        }

        int op1 = 1e9, op2 = 1e9, op3 = 1e9, skip = 1e9;

        if(st.count(day)) {
            op1 = costs[0] + solve(days, costs, day+1, lastDay, st);
            op2 = costs[1] + solve(days, costs, day+7, lastDay, st);
            op3 = costs[2] + solve(days, costs, day+30, lastDay, st);
        }
        else {
            skip = solve(days, costs, day+1, lastDay, st);
        }

        return dp[day] = min({op1, op2, op3, skip});
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int lastDay = days.back();
        unordered_set<int> st(begin(days), end(days));

        memset(dp, -1, sizeof(dp));

        return solve(days, costs, 1, lastDay, st);
    }
};