class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left =0;
        int maxLen =0;
        std::unordered_set<char>charInS;
        for(int right = 0;right<s.size();right++){
            while(charInS.count(s[right])){
                charInS.erase(s[left]);
                left++;
            }
            charInS.insert(s[right]);
            maxLen = std::max(maxLen,right-left+1);
        }
        return maxLen;
    }
};