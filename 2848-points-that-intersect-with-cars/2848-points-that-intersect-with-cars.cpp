class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(begin(nums),end(nums));
        vector<vector<int>> merge;
        merge.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i][0]<=merge.back()[1]){
                merge.back()[1]=max(nums[i][1],merge.back()[1]);
            }
            else{
                merge.push_back(nums[i]);
            }
        }
        int count=0;
        for(auto &it : merge){
            int start=it[0];
            int end=it[1];

            count+=end-start+1;

        }
        return count;
        
    }
};