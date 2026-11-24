class Solution {
public:
    vector<vector<int>>ans;
    int n;
    void solve(vector<int>& nums , int target , vector<vector<int>>& ans , vector<int>& res , int idx){
        if(target==0){
            ans.push_back(res);
            return ;
        }
        if(idx>=n || target<0){
            return ;
        }

        res.push_back(nums[idx]);
        solve(nums,target-nums[idx],ans,res,idx);
        res.pop_back();

        solve(nums,target,ans,res,idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<int>res;
        solve(candidates,target,ans,res,0);
        return ans;
        
    }
};