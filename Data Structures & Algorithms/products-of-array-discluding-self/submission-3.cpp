class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        size_t end = nums.size() - 1;

        auto prefix_product = vector<int>(nums.size());
        auto postfix_product = vector<int>(nums.size());

        prefix_product[0] = nums[0];    
        postfix_product[end] = nums[end];

        for (size_t i = 1; i < nums.size(); i++) {
            size_t j = end - i;

            prefix_product[i] = prefix_product[i - 1] * nums[i];
            postfix_product[j] = postfix_product[j + 1] * nums[j];
        }

        auto result = vector<int>(nums.size());
        result[0] = postfix_product[1];
        result[end] = prefix_product[end-1];

        for (size_t k = 1; k < nums.size() - 1; k++) {
            result[k] = prefix_product[k-1] * postfix_product[k+1];
        }

        return result;
    }
};
