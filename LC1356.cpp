#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Custom comparator
    static bool cmp(pair<int,int>& a , pair<int,int>& b){
        if(a.first == b.first){
            return a.second < b.second;   // if same bit count, sort by number
        }
        return a.first < b.first;         // sort by bit count
    }

    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> oneBit;

        // Store (bitcount, number)
        for(int num : arr){
            int count = __builtin_popcount(num);
            oneBit.push_back({count, num});
        }

        // Sort using custom comparator
        sort(oneBit.begin(), oneBit.end(), cmp);

        // Extract sorted numbers
        vector<int> result;
        for(auto &p : oneBit){
            result.push_back(p.second);
        }

        return result;
    }
};

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    Solution obj;
    vector<int> result = obj.sortByBits(arr);

    cout << "Sorted array by bits: ";
    for(int num : result){
        cout << num << " ";
    }

    return 0;
}