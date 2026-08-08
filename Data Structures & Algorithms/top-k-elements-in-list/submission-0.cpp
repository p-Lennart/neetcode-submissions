class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        cout << "hsh";

        unordered_map<int, int> hsh;
        for (auto n : nums) {
            hsh[n] += 1;
        }

        cout << "rank";

        vector<vector<int>> ranking(nums.size() + 1, vector<int>());
        for (const auto& val : hsh) {
            auto n = val.first;
            auto occ = val.second;

            ranking[occ].push_back(n);
        }

        cout << "res";

        vector<int> res;
        for (int i = ranking.size() - 1; i > 0; i--) {
            for (auto n : ranking[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }

        cout << "done";

        return res;
    }
};
