class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        if (l == r) {
            if (nums[0] == target) return 0;
            else                   return -1;
        }

        while (l < r) {
            int m = l + (r - l) / 2;
            if (target == nums[l]) return l;
            if (target == nums[m]) return m;
            if (target == nums[r]) return r;

            if (nums[m] < nums[l]) { // seam on left; focus on sorted right
                if (target > nums[m] && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            } else if (nums[m] > nums[r]) { // seam on right; focus on sorted left
                if (target >= nums[l] && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else { // m between l and r, perfectly sorted
                if (target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }

        return -1;
    }
};
