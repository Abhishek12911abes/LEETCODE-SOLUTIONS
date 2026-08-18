class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            return *max_element(begin(nums),end(nums));
        }
        unordered_map<int,int>mp;
        for(int num : nums){
            mp[num]++;
        }
        int maxi=-1;
        if(k==1){
            for(auto &it : mp){
                if(it.second==1){
                    maxi=max(maxi,it.first);
                }
            }
            return maxi;
        }
        if(mp[nums[0]]>1 && mp[nums[n-1]]>1){
           return -1;
        }
        else if(mp[nums[0]]>1){
            return nums[n-1];
        }
        else if(mp[nums[n-1]]>1){
            return nums[0];
        }
            
        return max(nums[0],nums[n-1]);
    }
};