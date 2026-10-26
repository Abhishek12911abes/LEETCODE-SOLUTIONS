
class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        vector<pair<string, int>> events = {
            {event1[0], 1}, {event1[1], -1}, {event2[0], 1}, {event2[1], -1}};

        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });

        int count = 0;

        for (auto& e : events) {
            count += e.second;

            if (count > 1)
                return true;
        }

        return false;
    }
};
