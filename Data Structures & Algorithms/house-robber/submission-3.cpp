class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // can't sort: adjacency matters
        // linear pass
        // what should state be? optimal at, or optimal including
        // optimal including: split into 2 states, optimal is the max of both
        vector<int> take(n, 0);
        vector<int> leave(n, 0);

        if (n == 0) return 0;
        
        take[0] = nums[0];
        leave[0] = 0;

        if (n == 1) return take[0];

        take[1] = nums[1];
        leave[1] = nums[0];

        if (n == 2) return max(take[1], leave[1]);

        for (int i = 2; i < nums.size(); i++) {
            take[i] = leave[i-1] + nums[i];
            leave[i] = max(leave[i-1], take[i-1]);
        }

        return max(take[n-1], leave[n-1]);

    }
};
