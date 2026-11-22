class Solution {
public:
    bool solve(int n){
        if(n==1){
            return false;
        }
        else if(n==2){
            return true;
        }
        for(int i=1;i<n;i++){
            if(n%i==0){
                return !solve(n-i);
            }
        }
        return false;
    }
    bool divisorGame(int n) {
        if(n==1){
            return false;
        }
        else if(n==2){
            return true;
        }
        return solve(n);
        
    }
};