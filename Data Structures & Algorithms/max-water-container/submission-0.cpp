class Solution {
public:
    int getArea(vector<int>& heights, int i1, int i2) {
        return min(heights[i2], heights[i1]) * (i2 - i1);
    }

    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int maxarea = 0;

        while (left < right) {
            int area = getArea(heights, left, right);
            maxarea = max(maxarea, area);
            
            int h1 = heights[left];
            int h2 = heights[right];
            if (h2 < h1) {
                right--;
            } else {
                left++;
            }
        }

        return maxarea;
    }
};
