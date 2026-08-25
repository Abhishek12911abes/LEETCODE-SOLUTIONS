class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_set<int>st(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            if(!st.count(k*(i+1))){
                return k*(i+1);
            }
        }
        return k*(n+1);
    }
};