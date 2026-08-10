class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& sortedNums, int target) {
        int i = 0;
        int j = sortedNums.size() - 1;

        vector<vector<int>> results;

        while (i < j) {
            int sum = sortedNums[i] + sortedNums[j];
            
            if (sum > target) {
                j--;
                continue;
            }
            if (sum < target) {
                i++;
                continue;
            }
        
            results.push_back({i, j});
            i++;
        }

        return results;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return vector<vector<int>>();

        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        unordered_map<int, unordered_map<int, unordered_map<int, bool>>> found; 

        for (int k = 0; k < nums.size(); k++) {
            auto matches = twoSum(nums, -1 * nums[k]);
            for (auto match : matches) {
                if (match.size() != 2) continue;

                int i = match[0];
                int j = match[1];

                if (k == i || k == j || i == j) continue;

                vector<int> t = {nums[i], nums[j], nums[k]};
                sort(t.begin(), t.end());

                if (found.find(t[0]) != found.end()
                    && found[t[0]].find(t[1]) != found[t[0]].end()
                    && found[t[0]][t[1]].find(t[2]) != found[t[0]][t[1]].end())
                        continue;

                result.push_back(t);
                found[t[0]][t[1]][t[2]] = true;
            }
        }
        return result;
    }
};
