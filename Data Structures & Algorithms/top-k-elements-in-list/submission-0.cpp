class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> int_to_freq;
        for(int i : nums){
            int_to_freq[i]++;
        }
        using pi = std::pair<int, int>;
        std::priority_queue<pi,vector<pi>,std::greater<pi>> minh;
        int size =0;
        for(auto[i,freq] : int_to_freq){
            minh.push({freq,i});
            size++;
            if(size>k){
                minh.pop();
                size--;
            }
        }
        std::vector<int> result;
        while(!minh.empty()){
            auto[freq,i] = minh.top();
            minh.pop();
            result.push_back(i);
        }
        return result;
    }
};
