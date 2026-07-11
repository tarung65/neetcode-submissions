class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 1);
        int left_product = 1;
        for (int i = 0; i < size; i++) {
            result[i] = left_product;
            left_product *= nums[i];
        }
        // Step 2: Compute suffix products on the fly moving backwards
        // Multiply the existing prefix product with the running suffix product
        int right_product = 1;
        for (int i = size - 1; i >= 0; i--) {
            result[i] *= right_product;
            right_product *= nums[i];
        }
        return result;
    }
};
