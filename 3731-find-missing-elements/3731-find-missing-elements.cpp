class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();

        int mini=INT_MAX,maxi=INT_MIN;

        for(int i=0;i<n;i++){
            mini=min(mini,nums[i]);
            maxi=max(maxi,nums[i]);
        }
        unordered_set<int>st;
        vector<int>ans;
        for(int num : nums){
           st.insert(num);
        }
        for(int i=mini;i<=maxi;i++){
            if(!st.count(i)){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};