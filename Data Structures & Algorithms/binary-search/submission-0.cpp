class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        while(start <= end){
            int i = (start+end)/2;
            if (nums[i] == target) return i;
            else if(nums[i] < target) start = i+1;
            else end = i-1;
        }
        return -1;
    }
};
