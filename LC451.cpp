#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        
        // Step 1: Count frequency of each character
        unordered_map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }

        // Step 2: Create max heap based on frequency
        priority_queue<pair<int, char>> pq;
        for(auto &it : mp){
            pq.push({it.second, it.first});
        }

        // Step 3: Build result string
        string ans = "";
        while(!pq.empty()){
            
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();

            while(freq--){
                ans += ch;
            }
        }

        return ans;
    }
};

int main() {
    
    Solution obj;
    
    string s;
    cout << "Enter string: ";
    cin >> s;

    string result = obj.frequencySort(s);
    
    cout << "Sorted by frequency: " << result << endl;

    return 0;
}