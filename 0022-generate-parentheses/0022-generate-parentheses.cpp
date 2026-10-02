class Solution {
public:
    bool balance(string &temp){
        int open=0,close=0;
        for(char c : temp){
            if(open-close<0){
                return false;
            }
            if(c=='('){
                open++;
            }
            else{
                close++;
            }
        }
        return open-close==0;
    }
    void solve(int n , vector<string>& ans , string temp){
        if(temp.size()==2*n){
            if(balance(temp)){
                ans.push_back(temp);
                return;
            }
            return ;
        }

        temp.push_back('(');
        solve(n,ans,temp);
        temp.pop_back();

        temp.push_back(')');
        solve(n,ans,temp);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp;
        solve(n,ans,temp);
        return ans;
    }
};