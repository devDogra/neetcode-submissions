class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false; 

        int sf[26] = {0};

        // int uniques = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((sf[s[i] - 'a']++) == 0) {
                // uniques++;
            }
        }

        int zeros_made = 0;
        for (int i = 0; i < t.size(); i++) {
            // should hit zero s.size() ()== t.size()) times 
            int f = --sf[t[i] - 'a'];
            if (f < 0) {
                return false;
            } 
            // else if (f == 0) {
            //     zeros_made++;
            // }
        }

        return true;
    }
};
