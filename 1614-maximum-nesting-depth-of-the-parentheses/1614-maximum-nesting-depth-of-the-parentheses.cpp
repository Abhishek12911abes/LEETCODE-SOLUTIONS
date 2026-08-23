class Solution {
public:
    int maxDepth(string s) {
        int n=s.size();
        int maxi=0;
        int countOpen=0;
        for(char c : s){
            if(c=='('){
                countOpen++;
                maxi=max(maxi,countOpen);
            }
            else if(c==')'){
                countOpen--;
                // maxi=max(maxi,countOpen);
            }
            
        }
        return maxi;
        
    }
};