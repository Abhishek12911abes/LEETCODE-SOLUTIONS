class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.size();
        unordered_map<string,string>mp;
        for(auto s : knowledge){
            string key=s[0];
            string val=s[1];
            mp[key]=val;
        }
        string ans;
        int i=0;
       while(i<n){
            if(s[i]=='('){
                int j=i+1;
                string temp;
                while(s[j]!=')'){
                    temp+=s[j];
                    j++;
                }
                if(mp.count(temp)){
                    ans+=mp[temp];
                }
                else{
                    ans+='?';
                }
                temp.clear();
                i=j+1;
            }
            else{
                ans+=s[i];
                i++;
            }
        }
        return ans;
    }
};