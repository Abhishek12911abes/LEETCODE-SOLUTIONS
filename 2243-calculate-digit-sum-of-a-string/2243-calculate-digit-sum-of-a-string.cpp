class Solution {
public:
    string digitSum(string s, int k) {
        int n=s.size();
        string temp=s;
        while(temp.size()>k){
            int sum=0;
            string t;
            int i=0;
            int p=1;
            while(i<temp.size()){
                sum+=(temp[i]-'0');
                // cout<<sum<<endl;
                if(i==k*p-1 || i==temp.size()-1){
                    if(sum>9){
                        string tempSum=to_string(sum);
                        int c=0;
                        while(c<tempSum.size()){
                            t+=tempSum[c++];
                        }
                    }
                    else{
                        t+=char(sum+'0');
                    }
                    sum=0;
                    p++;
                }
                i++;
            }
            temp=t;
            cout<<temp<<endl;
        }
        return temp;
        
        
    }
};