class Solution {
public:

string encode(vector<string>& strs) {
    string ans = "";
    for (int i = 0; i < strs.size(); i++) {
        ans += std::to_string(strs[i].size());
        ans.push_back('#'); 
        ans += strs[i]; 
    }
    cout << ans;
    return ans;
}

vector<string> decode(string s) {

    vector<string> words;
    int i = 0; 
    while(i < s.size()) {
        string numstr = "";
        while(isdigit(s[i])) {
            numstr.push_back(s[i]);
            i++;
        }

        i++;
        int num = std::stoi(numstr);

        string word = "";
        while(i < s.size() && num--) {
            word.push_back(s[i]);
            i++;
        }
        // if (word.size() > 0) 
            words.push_back(word);

    }

    return words; 
}

};
