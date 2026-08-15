class Solution {
public:
    int findMin(vector<int> &nums) {
        // flashback to cs182
        // log n -> binary search
        // want to find the "seam": 5 6 -> 1
        // the one point it decreases is the min

        int l = 0;
        int r = nums.size() - 1;

        if (l == r) return nums[0];
        
        while (true) {
            int m = l + (r - l) / 2;
            
            if (l == r-1) {
                if (nums[l] < nums[r]) return nums[l];
                else                   return nums[r];
            }

            if (nums[m] < nums[r]) {
                // right half is ascending normally. seam is on the left.
                r = m;                
            } else {
                // right half contains a reset.
                l = m;
            }
        }
    }
};
