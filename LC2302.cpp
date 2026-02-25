#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0;
        long long sum = 0;
        long long count = 0;

        for(int j = 0; j < n; j++) {
            sum += nums[j];

            // Shrink window until score < k
            while(i <= j && sum * (j - i + 1) >= k) {
                sum -= nums[i];
                i++;
            }

            // All subarrays ending at j and starting from i to j are valid
            count += (j - i + 1);
        }

        return count;
    }
};

int main() {
    int n;
    long long k;
    
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> nums(n);
    
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    long long result = obj.countSubarrays(nums, k);
    
    cout << "Number of valid subarrays: " << result << endl;

    return 0;
}