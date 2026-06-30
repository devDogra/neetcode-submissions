class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        
        int maxar = 0;
        while(l < r) {
            int ar = area(heights, l, r);
            maxar = max(maxar, ar);

            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return maxar;
    }

    int area(vector<int>& heights, int l, int r) {
        return min(heights[l], heights[r]) * (r - l);
    }
};
