class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        if(n==1){
            return strs[0];
        }
        int minLen=INT_MAX;
        string temp;

        for(string &s : strs){
            if((int)s.size()<minLen){
                minLen=(int)s.size();
                temp=s;
            }
        }

        int j=0;
        string ans;
        while(j<minLen){
            char ch=temp[j];
            bool found=true;
            for(int i=0;i<strs.size();i++){
                if(strs[i][j]!=ch){
                    found=false;
                    break;
                }
            }
            if(found){
                ans+=ch;
            }
            else{
                break;
            }
            j++;
        }
        return !ans.empty()?ans:"";
    }
};