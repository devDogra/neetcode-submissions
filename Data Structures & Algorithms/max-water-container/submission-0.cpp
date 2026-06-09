class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size(); 
        int l = 0;
        int r = n-1;

        int max = 0;
        while(l < r) {
            int ar = area(l, r, heights);
            max = std::max(max, ar);
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[r] < heights[l]) {
                r--;
            } else {
                l++;
            }
        }

        return max;
    }

    int area(int l, int r, vector<int>& heights) {
        return std::max(0, (r-l) * std::min(heights[l], heights[r]));
    }
};
