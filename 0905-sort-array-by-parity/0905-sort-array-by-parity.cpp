class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=0;
        vector<int>ans(n);
        while(j<n){
            if(nums[j]%2==0){
                swap(nums[i],nums[j]);
                i++;
            }
            j++;
        }
        ans=nums;
        return ans;
        
    }
};