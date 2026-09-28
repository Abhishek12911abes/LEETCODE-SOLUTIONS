class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int maxLen=-1;
        for(char c : s){
            if(c=='('){
                st.push(c);
                maxLen=max(maxLen,(int)st.size());
            }
            else if(c==')'){
                st.pop();
            }
        }
        return maxLen==-1?0:maxLen;
        
    }
};