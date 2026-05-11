class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams; 
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];

            bool found_anagram = false;
            for (int j = 0; j < anagrams.size(); j++) {
                string a = anagrams[j][0];
                if (a.size() != s.size()) {
                    continue; // not anagram
                }
                // check if s is an anagram of a
                // a represents the whole list it's in
                // if s is anagram of a, it belomngs in a's list 
                int af[26] = {0};
                for (int k = 0; k < a.size(); k++) {
                    af[a[k] - 'a']++;
                }


                bool not_anagram = false;
                for (int l = 0; l < s.size(); l++) {
                    if (--af[s[l] - 'a'] < 0) {
                        // not anagram
                        // continue;
                        not_anagram = true;
                        break;
                    }
                }


                if (not_anagram) {
                    continue;
                }

                // couldnt make any 0 and the lengths r equal 
                // s is an anagram of a
                anagrams[j].push_back(s);
                found_anagram = true;
            }
            if (!found_anagram) {
                vector<string> newlist = {s};
                anagrams.push_back(newlist);
            }
        }

        return anagrams;
    }
};
