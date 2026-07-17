class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();

        vector<vector<string>>ans;

        unordered_map<string,vector<string>>mp;

        for(string str : strs){
            string temp=str;
            sort(begin(temp),end(temp));
            mp[temp].push_back(str);
        }

        for(auto &it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};