class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n=nums.size();

        int mini=*min_element(begin(nums),end(nums));
        int maxi=*max_element(begin(nums),end(nums));

        return gcd(mini,maxi);        
    }
};