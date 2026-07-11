class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() !=t.size()) return false;
        vector<int>chararr(26,0);
        for(int i =0;i<s.size();i++){
            chararr[s[i]-'a']++;
            chararr[t[i]-'a']--;
        }
        for(int i :chararr){
            if(i) return false;
        }
        return true;
    }
};
