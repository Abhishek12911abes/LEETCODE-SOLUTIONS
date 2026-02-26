#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    // Function to count subarrays with at most k distinct elements
    int atMost(vector<int>& nums, int k){
        int n = nums.size();
        unordered_map<int,int> mp;
        
        int i = 0, j = 0;
        int count = 0;
        
        while(j < n){
            
            // include current element
            mp[nums[j]]++;
            
            // shrink window if distinct elements > k
            while(mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            
            // add number of valid subarrays ending at j
            count += (j - i + 1);
            
            j++;
        }
        
        return count;
    }
    
    // Function to count subarrays with exactly k distinct elements
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};

int main(){
    
    Solution obj;
    
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    
    cout << "Number of subarrays with exactly " 
         << k << " distinct elements: ";
    
    cout << obj.subarraysWithKDistinct(nums, k) << endl;
    
    return 0;
}