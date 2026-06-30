class Solution {
public:
    int numSplits(string s) {
        int n=s.size();
        vector<bool>left(26,false);
        vector<int>lPref(n,0);
        vector<int>rSuff(n,0);
        lPref[0]=1;
        left[s[0]-'a']=true;
        for(int i=1;i<n;i++){
            int idx=s[i]-'a';
            if(left[idx]==true){
                lPref[i]=lPref[i-1];
            }
            else{
                lPref[i]=lPref[i-1]+1;
            }
            left[idx]=true;
        }
        for(int num : lPref){
            cout<<num<<" ";
            cout<<endl;
        }
        cout<<endl;
        left.clear();
        left.resize(26, false);
        rSuff[n-1]=1;
        left[s[n-1]-'a']=true;
        for(int i=n-2;i>=0;i--){
            int idx=s[i]-'a';
            if(left[idx]==true){
                rSuff[i]=rSuff[i+1];
            }
            else{
                rSuff[i]=rSuff[i+1]+1;
            }
            left[idx]=true;
        }
        for(int num : rSuff){
            cout<<num<<" ";
            
        }
        int count=0;
        for(int i=0;i<n-1;i++){
            if(lPref[i]==rSuff[i+1]){
                count++;
            }
        }
        return count;


        
    }
};