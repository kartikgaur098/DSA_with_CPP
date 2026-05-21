class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        vector<string> words;
        string word = "";

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                words.push_back(word);
                word = "";
            } else {
                word = word + s[i];
            }
        }

        words.push_back(word);
        if (pattern.size() != words.size())
            return false;
        for (int i = 0; i < pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];

            if (mp.find(ch) != mp.end()) {
                if (mp[ch] != word) {
                    return false;
                }
            } else {

                for (auto it : mp) {
                    if (it.second == word) {
                        return false;
                    }
                }

                mp[ch] = word;
            }
        }

        return true;
    }
};