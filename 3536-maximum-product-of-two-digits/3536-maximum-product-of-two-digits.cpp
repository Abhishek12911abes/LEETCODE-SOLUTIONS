class Solution {
public:
    int maxProduct(int n) {
        bool seen = false;
        int maxi=-1,smaxi=-1;
        while(n){
            if(n%10>maxi){
                smaxi=maxi;
                maxi=n%10;
            }
            else if(n%10>smaxi && maxi!=smaxi){
                smaxi=n%10;
            }
            n/=10;
        }
        return maxi*smaxi;
    }
};