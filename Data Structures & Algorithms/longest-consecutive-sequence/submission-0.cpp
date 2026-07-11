class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() <=1) return nums.size();
        std::unordered_set<int> hset;
        int maxseq = 1;
        for(int i : nums ) hset.insert(i);
        for(int i : hset){
            if(!hset.count(i-1)){
                int length = 1;
                while(hset.count(i+length)){
                    length++;
                }
                maxseq = max(length,maxseq);
            }
        }
        return maxseq;
    }
};
