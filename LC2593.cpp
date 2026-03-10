#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        int n = nums.size();
        long long score = 0;

        // Min Heap -> (value, index)
        priority_queue<pair<int,int>, 
                       vector<pair<int,int>>, 
                       greater<pair<int,int>>> pq;

        // Push all elements into heap
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }

        vector<bool> visited(n, false);

        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();

            int value = top.first;
            int idx = top.second;

            // If already marked, skip
            if(visited[idx]) continue;

            // Add to score
            score += value;

            // Mark current index
            visited[idx] = true;

            // Mark left neighbor
            if(idx - 1 >= 0)
                visited[idx - 1] = true;

            // Mark right neighbor
            if(idx + 1 < n)
                visited[idx + 1] = true;
        }

        return score;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 1, 3, 4, 5, 2};

    cout << sol.findScore(nums) << endl;   // Expected Output: 7

    return 0;
}