class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> int_freq;
        int max_freq = 0;
        for(int i : nums){
            int_freq[i]++;
            max_freq = max(int_freq[i],max_freq);
        }
        std::vector<std::vector<int>> bucket(max_freq+1);
        for(auto [i,freq] : int_freq){
            bucket[freq].push_back(i);
        }
        std::vector<int> result;
        result.reserve(k);
        for(int i = max_freq;i>0;i--){
            for(int num : bucket[i]){
                result.push_back(num);
                k--;
                if(k ==0)
                    return result;
            }
        }
        return result;

    }
};
