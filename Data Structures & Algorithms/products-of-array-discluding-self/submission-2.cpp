class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int32_t zeroless_prod = 1;
        int zero_count = 0;

        for (auto num : nums) {
            if (num != 0) {
                zeroless_prod *= num;
            } else {
                zero_count += 1;
            }
        } 

        auto result = vector<int>(nums.size());
        if (zero_count > 1) {
            return result;
        }

        for (size_t i{}; i < nums.size(); i++) {
            if (nums[i] == 0) {
                result[i] = zeroless_prod;
            } else if (zero_count == 0) {
                result[i] = zeroless_prod / nums[i];
            }
        }

        return result;
    }
};
