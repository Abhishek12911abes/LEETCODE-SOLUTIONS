#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        // Max heap: (frequency, character)
        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string result = "";
        
        while (!pq.empty()) {
            
            auto top1 = pq.top();
            pq.pop();
            
            int freq1 = top1.first;
            char ch1 = top1.second;
            
            // Check if adding this character creates 3 consecutive characters
            if (result.size() >= 2 &&
                result[result.size() - 1] == ch1 &&
                result[result.size() - 2] == ch1) {
                
                // If no alternative character available, stop
                if (pq.empty()) break;
                
                // Take second most frequent character
                auto top2 = pq.top();
                pq.pop();
                
                int freq2 = top2.first;
                char ch2 = top2.second;
                
                result.push_back(ch2);
                freq2--;
                
                // Push back if still remaining
                if (freq2 > 0)
                    pq.push({freq2, ch2});
                
                // Push first character back (since we didn't use it)
                pq.push({freq1, ch1});
            }
            else {
                result.push_back(ch1);
                freq1--;
                
                if (freq1 > 0)
                    pq.push({freq1, ch1});
            }
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    int a = 1, b = 3, c = 2;
    
    string ans = sol.longestDiverseString(a, b, c);
    
    cout << "Longest Happy String: " << ans << endl;
    
    return 0;
}