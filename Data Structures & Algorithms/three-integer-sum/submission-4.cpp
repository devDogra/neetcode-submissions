class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size(); 
        const int max = 1e5;
        std::sort(nums.begin(), nums.end());
        
        int idx[2*max + 1];
        for (int i = 0; i < 2*max+1; i++)  idx[i] = -1;
        for (int i = 0; i < n; i++) {
            idx[nums[i]+max] = i;
        }

        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            if (i != 0 and nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n; j++) {
                if (j != i+1 and nums[j] == nums[j-1]) continue;
                int comp = -(nums[i] + nums[j]);
                int compidx = (comp+max >= 0 and comp+max < 2*max+1) ? idx[comp+max] : -1;
                if (compidx > i and compidx > j) {
                    res.push_back(vector<int>{nums[i], nums[j], nums[compidx]});
                }
            }
        }

        return res;
    }
};
