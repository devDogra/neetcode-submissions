class Solution {
public:

    static bool compare(pair<int, int>& a, pair<int, int>& b) {
        bool order_correct = a.second > b.second;
        return order_correct;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> fmap;
        for (int i = 0; i < nums.size(); i++) {
            fmap[nums[i]]++;
        }

        vector<pair<int, int>> pairs(fmap.begin(), fmap.end());


        std::sort(pairs.begin(), pairs.end(), compare);

        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(pairs[i].first);
        }
        return res;

    }
};
