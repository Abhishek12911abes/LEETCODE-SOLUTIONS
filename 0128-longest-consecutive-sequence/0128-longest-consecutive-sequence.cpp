class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxLen=-1;

        unordered_set<int>st;

        for(int num : nums){
            st.insert(num);
        }

        for(int num : st){
            if(!st.count(num-1)){
                //mtlb consecutive elem yahi se suru ho rha;
                int count=0;
                while(st.count(num)){
                    count++;
                    num=num+1;
                }
                maxLen=max(maxLen,count);
            }
        }
        return maxLen==-1?0:maxLen;
        
        
    }
};