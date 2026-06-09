class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (i != 0 and nums[i] == nums[i-1]) continue;
            int l = i+1;
            int r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (r != n-1 and nums[r] == nums[r+1])  {
                    r--;
                    continue;
                }
                if (l != i+1 and nums[l] == nums[l-1]) {
                    l++; 
                    continue;
                }
                if (sum > 0) {
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                }
            }
        }

        return res;
    }
};
