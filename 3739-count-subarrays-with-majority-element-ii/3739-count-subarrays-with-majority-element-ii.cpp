class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size(); 

        // 2 2 2 2 7
        // har no ko aise treat kar agar num==target then +1 treat kr else -1

        // then array modify ho jaega
        // 1 1 1 1 -1
        // fhir iska cummalative sum le

        // 1 2 3 4 3

        // ek relation define hogi cummSum[j]-cummSum[i-1]>0 -> cummSum[j]>cummSum[i-1]

        // ab koi bhi jth index pakad le and koi bhi uske left side ka ith index lele if(cummSum[j]>cummSum[i-1]) then i se j ek valid subaarray hoga


        // ab maan le cummSum at index 3 -> 4 hai toh mai dekhunga ki past me aise jitne i the jinka sum 4 se kam tha ----> so i= 0 ,1 ,2 valid i hai

        // usko mai map me store kr lunga

        // map me kya rakhenge 

        // key--> cummSum 
        // val-->ye cummSum map me kitni baar dekh chuke hai


        unordered_map<int,int> mp;   // mp[cumSum] = frequency of how many times cumSum has occurred
        
        int currSum = 0;
        
        mp[0] = 1; //we have seen cumSum = 0 in the beginning once

        long long validLeftPoints = 0;

        long long result = 0;

        for (int x : nums) {
            if (x == target) {
                validLeftPoints += mp[currSum];
                currSum++;
            } else {
                currSum--;
                validLeftPoints -= mp[currSum];
            }

            mp[currSum]++;

            result += validLeftPoints;
        }

        return result;
    }
};