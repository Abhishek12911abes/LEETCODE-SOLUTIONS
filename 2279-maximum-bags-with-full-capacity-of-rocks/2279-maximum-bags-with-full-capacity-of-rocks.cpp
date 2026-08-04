class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {

        int n = capacity.size();

        vector<int> need(n);

        for (int i = 0; i < n; i++) {
            need[i] = capacity[i] - rocks[i];
        }

        sort(need.begin(), need.end());

        int count = 0;

        for (int x : need) {
            if (x == 0) {
                count++;
            }
            else if (additionalRocks >= x) {
                additionalRocks -= x;
                count++;
            }
            else {
                break;
            }
        }

        return count;
    }
};