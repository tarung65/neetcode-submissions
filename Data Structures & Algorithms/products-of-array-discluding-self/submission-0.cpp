class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size =nums.size();
        vector<int> leftp(size);
        vector<int>rightp(size);
        
        int pl = 1;
        int pr = 1;
        for(int i =0;i<size;i++){
            leftp[i] = pl;
            rightp[size-i-1] = pr;
            pl = pl*nums[i];
            pr = pr*nums[size-i-1];
        }
        for(int i =0;i<size;i++){
            nums[i] = leftp[i]*rightp[i];
        }
        return nums;
    }
};
