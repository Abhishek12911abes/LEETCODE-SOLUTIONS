class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();

        string ans1,ans2;
        for(char c : s){
            if(c=='#' && ans1.empty()){
                continue;
            }
            if(c=='#' && !ans1.empty()){
                ans1.pop_back();
            }
            else{
                ans1+=c;
            }
        }
        for(char c : t){
            if(c=='#' && ans2.empty()){
                continue;
            }
            if(c=='#' && !ans2.empty()){
                ans2.pop_back();
            }
            else{
                ans2+=c;
            }
        }
        return ans1==ans2;
        
    }
};