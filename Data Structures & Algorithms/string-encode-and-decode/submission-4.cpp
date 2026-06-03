class Solution {
public:
    // cat, 12
    // #3#cat#2#12
    // cat, hello, fo#t, #3
    // #3cat#5hello#4fo#t#2#3
    string encode(vector<string>& strs) {
        int n = strs.size();
        string result = "";
        for (int i = 0; i < n; i++) {
            string s = strs[i];
            string prefix = "#" + std::to_string(s.size()) + "#";
            result += prefix; 
            result += s;
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string> res;
        if (s.size() == 0) return res; 

        int i = 0;
        while(i < s.size() && s[i] == '#') {
            // i is at a starting hash # always 
            string nexlenstr = "";
            int t = i+1;
            for (t = i+1; s[t] != '#';t++) {
                nexlenstr.push_back(s[t]);
            }
            int nexlen = std::stoi(nexlenstr);

            string nexstr = "";
            int p = t+1;
            for (p = t+1; p < t+1 + nexlen; p++) {
                nexstr.push_back(s[p]);
            }
            res.push_back(nexstr);

            i = p;

        }

        return res;
    }
};
