class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        unordered_map<char,int>mp;
        for(char c : s){
            mp[c]++;
        }
        vector<bool>used(26,false);
        for(int i=0;i<order.size();i++){
            if(mp.count(order[i])){
                string temp = string(mp[order[i]], order[i]);
                ans+=temp;
                used[order[i]-'a']=true;
            }
        }
        for(int i=0;i<s.size();i++){
            if(!used[s[i]-'a']){
                ans+=s[i];
            }
        }
        return ans;
        
    }
};