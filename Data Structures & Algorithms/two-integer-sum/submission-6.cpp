class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int maxel = 10000000;
        int minel = -maxel;

        // el + maxel => idx of el;
        vector<int> ans;
        vector<int> ei(2*maxel + 10000, -1);
        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i] + maxel;
            
            
            int complement = target - nums[i];
            // is the complement exists ? 
            if (complement > maxel or complement < minel) {
                // complement_key will overflow
            }
            int complement_key = target - nums[i] + maxel;

            if (complement_key >= 0 && 
                complement_key < ei.size() &&
                ei[complement_key] != -1
            ) 
            {
                // i, e
                ans.push_back(ei[complement_key]);
                ans.push_back(i);
                return ans;
            } 
            else {
                ei[key] = i; // key - maxel == nums[i] is at i
            }
        }

        return ans;

    }
};
