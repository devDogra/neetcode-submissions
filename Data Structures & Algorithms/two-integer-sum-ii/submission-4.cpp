class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int n = numbers.size();
        int l = 0; 
        int r = n-1;

        while(l < r) {
            int sum = numbers[l] + numbers[r];
            if (target == sum) {
                return vector<int>{l+1, r+1};
            } else if (target > sum) {
                l++;
            } else {
                r--;
            }
        }

        return vector<int>{-1,-1};
    }
};
