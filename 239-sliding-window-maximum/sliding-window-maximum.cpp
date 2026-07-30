class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        std::deque<int> dq;
        vector<int> result(n-k+1);
        for(int i =0;i<n;i++){
            if(!dq.empty() &&(i == dq.front()+k)) dq.pop_front();
            while((!dq.empty()) && nums[dq.back()]< nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
            if( i < k-1) continue;
            result[i-k+1] = nums[dq.front()];
            
        }
        return result;
    }
};