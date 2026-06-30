class Solution {
public:
    int trap(vector<int>& height) {
        int t = 0;
        int n = height.size();

        int total_w = 0;
        while(t < n) {
            // find next maxima 
            cout << "t = " << t << endl;
            while(!is_maxima(height, t) && t < n) t++;
            if (t == n) break;
            cout << "maxima at t = " << t << endl;



            // scan right

            int r = t;
            int l = t;
            int adv_to = t+1;
            do {
                r++;
            } while((r < n) && (height[r] < height[t]));

            int t2;
            if ((r < n) && (height[r] >= height[t])) {
                // found taller bar
                cout << "for t = " << t << " fouind taller bar at r = " << r << endl;
                for (t2 = t+1; t2 < r; t2++) {
                    int w_to_fill = height[t] - height[t2];
                    height[t2] += w_to_fill;
                    total_w += w_to_fill;

                }
                adv_to = t2;
            }


            // scan left
            do {
                l--;
            } while((l >= 0) && (height[l] < height[t]));

            int t3;
            if ((l != -1) && (height[l] >= height[t])) {
                // found taller bar 
                cout << "for t = " << t << " fouind taller bar at l = " << l << endl;

                for (t3 = t-1; t3 > l; t3--) {
                    int w_to_fill = height[t] - height[t3];
                    height[t3] += w_to_fill;
                    total_w += w_to_fill;
                }
            } else {
                // no taller bars left or right
                cout << "none taller for t = " << t << endl;
            }



            cout << "total water  = " << total_w << endl;
            
            t = adv_to;

        }


        return total_w;
    }

    

    int is_maxima(vector<int>& height, int i) {
        int n = height.size();
        if (i < 0 or i >= n) return false;
        if (n == 1) return true;
        if (i == 0) {
            return (height[i] >= height[i+1]);
        }
        if (i == n-1) {
            return (height[i] >= height[i-1]);
        }

        return (height[i] >= height[i+1]) and (height[i] >= height[i-1]);

    }
};
