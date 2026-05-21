class Solution {
public:
    string decodeMessage(string key, string message) {
        char start = 'a';
        int index = 0;
        unordered_map<char, char> mp;
        char space = ' ';
        mp[space] = space;

        while (start <= 'z' && index < key.length()) {
            char currChar = key[index];
            if (mp.find(currChar) != mp.end()) {
                index++;
            } else {
                mp[currChar] = start;
                index++;
                start++;
            }
        }

        string ans = "";
        for (int i = 0; i < message.length(); i++) {
            char msgChar = message[i];
            char ansChar = mp[msgChar];
            ans.push_back(ansChar);
        }

        return ans ;
    }

}
;