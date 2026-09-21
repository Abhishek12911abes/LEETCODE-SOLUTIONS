class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxLen=INT_MIN;

        unordered_set<int>st;
        for(int num : nums){
            st.insert(num);
        }

        for(int num : st){
            int len=0;
            if(st.find(num-1)==st.end()){
                while(st.count(num)){
                    len++;
                    maxLen=max(maxLen,len);
                    num++;
                }
            }
        }
        return maxLen==INT_MIN?0:maxLen;
    }
};