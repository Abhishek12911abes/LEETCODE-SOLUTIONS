class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        stringstream ss(s);
        string token;
        while(ss>>token){
            st.push(token);
        }
        string ans;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            ans+=" ";
        }
        if (!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;

        
    }
};