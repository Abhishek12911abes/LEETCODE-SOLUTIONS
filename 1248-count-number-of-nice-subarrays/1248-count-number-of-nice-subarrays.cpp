class Solution {
public:
    int n;
    int solve(vector<int>& nums , int k){
        int oddCount=0;
        int i=0,j=0;
        int count=0;
        while(j<n){
            oddCount=(nums[j]%2==1)?(oddCount+1):oddCount;
            while(oddCount>k){
                oddCount=(nums[i]%2==1)?(oddCount-1):oddCount;
                i++;
            }
            count+=(j-i+1);
            j++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        n=nums.size();

        return solve(nums,k) - solve(nums,k-1);
        
    }
};