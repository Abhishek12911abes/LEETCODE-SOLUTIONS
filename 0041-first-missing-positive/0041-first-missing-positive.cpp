class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();

        unordered_set<int>st;
        for(int num : nums){
            st.insert(num);
        }
        int mx=*max_element(begin(nums),end(nums));
        for(int i=1;i<=n;i++){
            if(!st.count(i)){
                return i;
            }
        }
        return n+1;
        
    }
};