class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxLen=-1;
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                len++;
                maxLen=max(maxLen,len);
            }
            else{
                len=1;
            }
        }
        int len2=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                len2++;
                maxLen=max(maxLen,len2);
            }
            else{
                len2=1;
            }
        }
        return max({maxLen,len,len2});
        
    }
};