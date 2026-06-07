class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        const int max = 1000;
        const int n = numbers.size();
        int idx[2*max + 100000];
        for (int i = 0; i < 2*max+100000; i++) idx[i] = -1;

        for (int i = n-1; i >= 0; i--) {
            idx[numbers[i] + max] = i;
        }

        for (int i = 0; i < n; i++) {
            int comp = target - numbers[i];
            int idxcomp = idx[comp + max];
            
            if (idxcomp != -1 && idxcomp < i) {
                return vector<int>{ idxcomp+1, i+1 };
            }
        }
//idx 4 has 8
// idx 5 has 10
// [0, 999]
// idx 0 has 0
// idx 999 would have 1998
        return vector<int> {-1, -1};
    }
};
