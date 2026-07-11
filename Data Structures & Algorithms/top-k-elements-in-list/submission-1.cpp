class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> int_to_freq;
        int max_freq =0;
        for(int i : nums){
            int_to_freq[i]++;
            max_freq = max(max_freq, int_to_freq[i]);
        }
        std::vector<std::vector<int>> bucket(max_freq+1);
        for(auto[i,freq] : int_to_freq){
            bucket[freq].push_back(i);
        }
        std::vector<int> result;
        int size = 0;
        for(int i =max_freq;i>0;i--){
            if(bucket[i].size()== 0) continue;
            for(auto num : bucket[i]){
                result.push_back(num);
                size++;
                if(size == k) return result;
            }
        }
        return result;
    }
};
