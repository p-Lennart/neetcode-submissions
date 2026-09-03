class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> resHistograms;

        sort(nums.begin(), nums.end());
        vector<int> hist = vector<int>(31, 0);
        brancher(nums, target, resHistograms, 0, hist, 0);

        vector<vector<int>> result;
        for (vector<int> hist : resHistograms) {
            vector<int> res;
            for (int i = 1; i < 31; i++) {
                for (int j = 0; j < hist[i]; j++) {
                    res.push_back(i);
                }
            }
            result.push_back(res);
        }

        return result;
    }
private:
    void brancher(
        vector<int>& nums,
        int target,
        vector<vector<int>> &result,
        int sum,
        vector<int> &hist,
        int startIdx
    ) {
        // assume nums sorted
        for (int i = startIdx; i < nums.size(); i++) {
            int el = nums[i];
            int newsum = sum + el;

            if (newsum > target) {
                break;
            } else if (newsum == target) {
                hist[el]++;
                result.push_back(hist);
                hist[el]--;
                break; // all future elements would make sum too large
            } else {
                hist[el]++;
                brancher(nums, target, result, newsum, hist, i);
                hist[el]--;
            }
        }
    }
};
