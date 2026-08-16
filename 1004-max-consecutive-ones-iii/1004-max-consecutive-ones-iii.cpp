class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int maxLen=0;
        int i=0,j=0;
        unordered_map<int,int>mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp[0]>k){
                if(nums[i]==0){
                    mp[nums[i]]--;
                }
                if(mp[nums[i]]==0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            if(mp[0]<=k){
                maxLen=max(maxLen,j-i+1);
            }
            j++;
        }
        return maxLen;
    }
};