class Solution {
public:
    //               qi<----|
    //---------->pi
    // [] [] [] [] 0 [] [] []
    ///////////////////// o ///////////
    vector<int> productExceptSelf(vector<int>& nums) {
        // let pi = product of all from [0...i]
        // let qi = product of all from [i....n-1] 
        // output_i = p(i-1) * q(i+1);
        int n = nums.size();
        vector<int> p(n, 1);
        vector<int> q(n, 1);

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                p[i] = nums[i];
            } else {
                p[i] = p[i-1] * nums[i];
            }
        }

        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                q[i] = nums[i];
            } else {
                q[i] = q[i+1] * nums[i];
            }
        }

        vector<int> o(n, 1);
        for (int i = 0; i < n; i++) {
            if (i-1 >= 0) o[i] *= p[i-1];
            if (i+1 <= n-1) o[i] *= q[i+1];
        }

        return o;
    }
};
