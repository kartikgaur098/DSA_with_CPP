class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> vector;

        for (int i = 0; i < s.size(); i++) {
            char currChar = s[i];

            if (!vector.empty() && vector.back().first == currChar) {
                vector.back().second++;

                if (vector.back().second == k) {
                    vector.pop_back();
                }

            } else {
                vector.push_back({currChar, 1});
            }
        }
        string ans = "";
        for (int i = 0; i < vector.size(); i++) {
            char ch = vector[i].first;
            int count = vector[i].second;

            for (int j = 0; j < count; j++) {
               ans.push_back(ch);
            }
        }
        return ans;
    }
};