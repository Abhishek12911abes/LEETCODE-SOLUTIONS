class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n=groupSizes.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>>res;
        for(auto &it : mp){
            int groupSize=it.first;
            vector<int>& temp=it.second;
            vector<int>ans;
            int i=0;
            while(i<temp.size()){
                if((int)ans.size()==groupSize){
                    res.push_back(ans);
                    ans.clear();
                }
                ans.push_back(temp[i]);
                i++;
            }
            res.push_back(ans);
        }
        return res;

        
    }
};