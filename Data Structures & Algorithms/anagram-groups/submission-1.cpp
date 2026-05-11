class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // foreach string, calcc its fmap as a string, store it in map: fmap->[str]
        // then just return all [ [str] ]
        // fmap_to_strlist
        unordered_map<string, vector<string>> fmtosl;
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];

            int sfmap[26] = {0};
            for (int j = 0; j < s.size(); j++) {
                sfmap[s[j] - 'a']++;
            }

            string sfmap_key = "";
            for (int k = 0; k < 26; k++) {
                sfmap_key += to_string(sfmap[k]);
                sfmap_key += ",";
            }

            if (fmtosl.find(sfmap_key) == fmtosl.end()) {
                fmtosl[sfmap_key] = vector<string>();
            }
            fmtosl[sfmap_key].push_back(s);
        }

        vector<vector<string>> res;

        for (auto row = fmtosl.begin(); row != fmtosl.end(); row++) {
            res.push_back(row->second);
        }

        return res;
    }
};
