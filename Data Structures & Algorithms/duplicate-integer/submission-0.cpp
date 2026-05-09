class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (s.find(num) != s.end()) {
                cout << "t for " << endl; 
                cout << num << endl;
                return true;
            }
            s.insert(num);
        }
        return false;
    }
};