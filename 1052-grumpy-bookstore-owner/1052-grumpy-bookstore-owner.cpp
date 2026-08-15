class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();

        int score=0;

        for(int i=0;i<n;i++){
            if(grumpy[i]==0){
                score+=customers[i];
            }
        }

        cout<<score;

        int maxi=INT_MIN;
        int val=0;
        int i=0,j=0;
        while(j<n){
            if(grumpy[j]==1){
                val+=customers[j];
            }
            if(j-i+1>minutes){
                if(grumpy[i]==1){
                    val-=customers[i];
                }
                i++;
            }
            if(j-i+1==minutes){
                maxi=max(maxi,val);
            }
            j++;
        }
        return score+maxi;
        
    }
};