class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<char>st;
        int ops=0;
        for(char c : s){
            if(c=='('){
                st.push(c);
            }
            else{
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
                else{
                    ops++;
                }
            }
        }
        return st.size()+ops;
        
    }
};