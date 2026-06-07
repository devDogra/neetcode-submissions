class Solution {
public:

    bool isPalindrome(string s) {
        // 0 1 2 3 4 5
        // c a t t a c 
        // c a t a c
        // l         r
        int l = 0;
        int r = s.size()-1;

        while(l <= r) {
            if (!isalnum(s[l])) {
                l++;
                continue;
            } 
            if (!isalnum(s[r])) {
                r--;
                continue;
            }

            char lc = s[l];
            if (lc >= 'a') {
                lc = lc - 'a';
            } else if (lc >= 'A') {
                lc = lc - 'A';
            } 


            char rc = s[r];
            if (rc >= 'a') {
                rc = rc - 'a';
            } else if (rc >= 'A') {
                rc = rc - 'A';
            } 


            if (lc != rc) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
