class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &it : mp){
            vector<int>idx=it.second;
            if(idx.size()>=2){
                for(int i=1;i<idx.size();i++){
                    if(idx[i]-idx[i-1]<=k){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};