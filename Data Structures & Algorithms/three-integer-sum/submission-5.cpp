class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // sort it. we loop over (i, j) and see if a k exists such that
        // numsi + numsj + numsk = 0
        // to ensure we do not use duplicate numsi, numsj pairs, we 
        // always mmake sure i and j stop at unique values 
        // for example, for -4, -4, -1, -1, 
        // if i = the firs -4, and j = the first -1, 
        // if we do j++ and it arrives at the 2nde -1, we've justt used the same 
        // (-4, -1) pairs again
        // what about for -4 -4 -1 -1 -1 -1 8 8
        // if i = the first -1 and j = the 2nd -1? 
        // again, we've used (-1, -1) already, so we push j to the next num aka 8
        // then use (-1, 8)
        // i will always use a different val, spo willl j
        // if i will never be the same, then i will equal -4 only once
        // so psvbl pairs = (-4, _)
        // while we ccould still get -4,-1, and -4,-1, we do the same with j
        
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
