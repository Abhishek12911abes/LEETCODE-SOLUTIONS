class Solution {
public:
    long long smallestNumber(long long num) {
        string temp=to_string(num);
        int zeroCount=0;
        vector<char>vec;
        for(char c : temp){
            if(c=='0'){
                zeroCount++;
            }
            vec.push_back(c);
        }
        string ans;
        if(num>0 && vec.size()>=2){
            sort(begin(vec),end(vec));
            char firstNonNeg=-1;
            int idx=-1;
            for(int i=0;i<vec.size();i++){
                if(vec[i]!='0'){
                   firstNonNeg=vec[i]; 
                   idx=i;
                   break;
                }
            }
            if(zeroCount>0){
                ans+=firstNonNeg;
                while(zeroCount--){
                    ans+='0';
                }
                for(int i=idx+1;i<vec.size();i++){
                    ans+=vec[i];
                }
            }
            else{
                for(int i=0;i<vec.size();i++){
                    ans+=vec[i];
                }
            }
            if(!ans.empty()){
                return stoll(ans);
            }
        }
        else if(num<0){
            sort(rbegin(vec),rend(vec));
            ans+='-';
            for(char c : vec){
                ans+=c;
            }
            if(!ans.empty()){
                return stoll(ans);
            }
        }

        return 0;
        
    }
};