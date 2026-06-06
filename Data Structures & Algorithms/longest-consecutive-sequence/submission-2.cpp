class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        unordered_map<int, int> exist;
        int max = nums[0];
        int min = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            max = std::max(max, nums[i]);
            min = std::min(min, nums[i]);
            exist[nums[i]] = i;
        }


        int r = min-1;
        int wsz = 0;
        int ans = 0;
        do {
            r++;
            bool r_exist = exist.find(r) != exist.end();
            if (r_exist) {
                wsz++;
                ans = std::max(wsz, ans);
            } else {
                wsz = 0;
            }
        } while(r <= max-1);

        return ans;


    }
};
