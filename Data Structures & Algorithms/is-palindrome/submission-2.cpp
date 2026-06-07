class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size()-1;

        while(l <= r) {
            while(!isalnum(s[l])) {
                l++;
            }
            while(!isalnum(s[r])) {
                r--;
            }
            
            if (l > r) break;

            char lc = s[l];
            lc = (lc >= 'a') 
                ? lc - 'a'
                : (lc >= 'A') 
                    ? lc - 'A'
                    : lc;

            char rc = s[r];
            rc = (rc >= 'a') 
                ? rc - 'a'
                : (rc >= 'A') 
                    ? rc - 'A'
                    : rc;

            if (lc != rc) return false;
            l++;
            r--;
        }

        return true;
    }
};
