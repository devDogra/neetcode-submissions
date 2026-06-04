class Solution {
public:
    // i from n.....1
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

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                p[i] = nums[i];
            } else {
                p[i] = p[i-1] * nums[i];
            }
        }

        int qi_prev = 1;
        for (int i = n; i >= 1; i--) {
            int qi = qi_prev * ((i == n) ? 1 : nums[i]);
            int oi = qi      * ((i == 1) ? 1 : p[i-2]);
            
            p[i-1] = oi;
            qi_prev = qi;
        }

        return p;
    }
};
