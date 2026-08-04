class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks,int additionalRocks) {
        int n = capacity.size();

        vector<pair<int, int>> v(n);
        for (int i = 0; i < n; i++) {
            v[i] = {capacity[i], rocks[i]};
        }
        sort(v.begin(), v.end(), [](auto& a, auto& b) {
            return (a.first - a.second) < (b.first - b.second);
        });
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (v[i].first == v[i].second) {
                count++;
                continue;
            } else if (v[i].first > v[i].second + additionalRocks) {
                continue;
            } else {
                int need = v[i].first - v[i].second;
                additionalRocks -= need;
                count++;
            }
        }
        return count;
    }
};