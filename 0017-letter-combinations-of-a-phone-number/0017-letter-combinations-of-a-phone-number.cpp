class Solution {
public:
    int n;
    void solve(string& digits , vector<string>& ans , int idx , unordered_map<int,vector<char>>& mp , string temp){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        if(idx>=n){
            return ;
        }
        for(char c : mp[digits[idx]-'0']){
            temp.push_back(c);
            solve(digits,ans,idx+1,mp,temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        unordered_map<int, vector<char>> mp;
        char ch = 'a';
        for (int i = 2; i <= 9; i++) {

            int limit = (i == 7 || i == 9) ? 4 : 3;

            for (int j = 0; j < limit; j++) {
                mp[i].push_back(ch);
                ch = char(ch + 1);
            }
        }
        string temp;
        vector<string>ans;
        solve(digits,ans,0,mp,temp);
        return ans;
    }
};