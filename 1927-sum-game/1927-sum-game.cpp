class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int firstHalf=0,secondHalf=0;

        int sum1=0,sum2=0;

        for(int i=0;i<n;i++){
            if(2*i<n){
                if(num[i]=='?'){
                    firstHalf++;
                }
                else{
                    sum1+=(num[i]-'0');
                }
            }
            else{
                if(num[i]=='?'){
                    secondHalf++;
                }
                else{
                    sum2+=(num[i]-'0');
                }
            }
        }
        cout<<firstHalf<<" "<<secondHalf;

        if(firstHalf==n/2 && secondHalf==0){
            if(sum2==9){
                return true;
            }
            return false;
        }
        else if(firstHalf==0 && secondHalf==n/2){
            if(sum1==9){
                return false;
            }
            return true;
        }

        if(firstHalf==0 && secondHalf==0 && sum1!=0 && sum2!=0){
            return !(sum1>=sum2);
        }
        else if(secondHalf==firstHalf){
            if(sum1==0 && sum2==0){
                return false;
            }
            else if(sum2>sum1){
                return false;
            }
            else if(sum1==sum2){
                return false;
            }
            else{
                return true;
            }
        }
        else if(firstHalf>secondHalf){
            return true;
        }
        else if(secondHalf>firstHalf){
            if(sum1<sum2){
                return true;
            }
        }
        return false;     
    }
};